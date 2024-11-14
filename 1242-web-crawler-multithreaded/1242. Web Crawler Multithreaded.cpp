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
    mutex m;
    condition_variable cv;
    int active_threads;
    queue<string> q;
    vector<string> ans;
    unordered_set<string> vis;
    bool stop;
    string getHostName(string s){
        int pos = string("https://").size();
        pos = s.find("/",pos);
        return s.substr(0,pos);
    }
    void worker(HtmlParser &htmlParser){
        string s;
        while(true){
            {
                unique_lock<mutex> guard(m);
                cv.wait(guard,[&](){return !q.empty() or stop;});
                if(stop)break;
                active_threads++;
                s = q.front();
                q.pop();
                cv.notify_one();
            }
            vector<string> to_vis;
            for(auto v:htmlParser.getUrls(s)){
                if(hname==getHostName(v)){
                    to_vis.push_back(v);
                }
            }
            shared_ptr<int> t = make_shared<int>(5);
            {
                unique_lock<mutex> guard(m);
                for(auto v:to_vis){
                    if(!vis.contains(v)){
                        vis.insert(v);
                        ans.push_back(v);
                        q.push(v);
                    }
                }
                active_threads--;
                if(q.empty() and !active_threads) stop=true;
                if(stop) break;
                cv.notify_one();
            }
        }
        cv.notify_one();
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hname = getHostName(startUrl);
        stop = false;
        vector<thread> thread_pool;
        q.push(startUrl);
        vis.insert(startUrl);
        ans.push_back(startUrl);
        for(int i = 0;i<thread::hardware_concurrency();i++){
            thread_pool.emplace_back(thread([&](){return worker(htmlParser);}));
        }
        for(int i = 0;i<thread_pool.size();i++){
            thread_pool[i].join();
        }
        return ans;

    }
};