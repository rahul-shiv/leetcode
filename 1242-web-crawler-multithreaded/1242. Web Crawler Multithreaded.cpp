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
        while(true){
            string url;
            {
                unique_lock<mutex> guard(m);
                cv.wait(guard, [this](){ return stop or !q.empty();});
                if(stop) break;
                active_threads++;
                url = q.front();
                ans.push_back(url);
                q.pop();
                cv.notify_one();
            }
            vector<string> url_list;
            for(auto next_url:htmlParser.getUrls(url)){
                if(hname == getHostName(next_url)){
                    url_list.push_back(next_url);
                }
            }
            {
                lock_guard<mutex> guard(m);
                for(auto next_url:url_list){
                    if(!vis.contains(next_url)){
                        vis.insert(next_url);
                        q.push(next_url);
                    }
                }
                active_threads--;
                if(active_threads==0 and q.empty()){
                    stop = true;
                    break;
                }
            }
        }
        cv.notify_one();
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hname = getHostName(startUrl);
        vector<thread> thread_pool;
        stop = false;
        active_threads = 0;
        q.push(startUrl);
        vis.insert(startUrl);
        for(int i = 0;i<thread::hardware_concurrency();i++){
            thread_pool.emplace_back(thread([&](){worker(htmlParser);}));
        }
        for(auto &t:thread_pool){
            t.join();
        }
        return ans;
    }
};