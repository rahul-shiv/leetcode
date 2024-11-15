/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
    string hname;
    vector<string> ans;
    int at;
    mutex m;
    condition_variable cv;
    queue<string> q;
    unordered_set<string> vis;
    bool stop;
    string getHostName(string s){
        int pos = string("https://").size();
        pos = s.find("/",pos);
        return s.substr(0,pos);
    }
    void worker(HtmlParser &htmlParser){
        string curr;
        while(true){
            {
                unique_lock<mutex> guard(m);
                cv.wait(guard,[&](){return stop or !q.empty();});
                if(stop) break;
                at++;
                curr = q.front();
                q.pop();
                cv.notify_one();
            }
            ans.push_back(curr);
            vector<string> vec;
            for(auto &v:htmlParser.getUrls(curr)){
                if(getHostName(v)==hname)vec.push_back(v);
            }
            {
                scoped_lock<mutex> guard(m);
                for(auto &v:vec){
                    if(!vis.contains(v)){
                        vis.insert(v);
                        q.push(v);
                    }
                }
                at--;
                if(!at and q.size()==0){
                    stop=1;
                    break;
                }
                cv.notify_one();
            }

        }
        cv.notify_one();
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        stop = false;
        hname = getHostName(startUrl);
        vector<thread> tp;
        vis.insert(startUrl);
        q.push(startUrl);
        for(int i = 0; i<thread::hardware_concurrency();i++){
            tp.emplace_back(thread([&](){return worker(htmlParser);}));
        }
        for(int i = 0;i<tp.size();i++){
            tp[i].join();
        }
        return ans;
    }
};