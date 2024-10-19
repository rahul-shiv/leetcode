/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
    mutex m;
    int ac;
    string hname;
    condition_variable cv;
    queue<string> q;
    vector<string> result;
    unordered_set<string> s;
    bool done;
    string extractHname(string &url){
        size_t pos = string("http://").size();
        pos = url.find('/', pos);
        if (pos == string::npos) {
            return url;
        }
        return url.substr(0, pos);
    }

    void worker(HtmlParser &htmlParser){
        while(true){
            string url;
            {
                unique_lock<mutex> guard(m);
                cv.wait(guard,[this](){
                    return !q.empty() or done;
                });
                if(q.empty() and done) break;
                url = q.front();
                q.pop();
                ac++;
            }
            vector<string> urls;
            for (auto v:htmlParser.getUrls(url)){
                if(extractHname(v)!=hname)continue;
                urls.push_back(v);
            }
            unique_lock<mutex> guard(m);
            for(auto v:urls){
                if(!s.contains(v)){
                    s.insert(v);
                    result.push_back(v);
                    q.push(v);
                }
            }
            ac--;
            if(ac==0 and q.empty()){
                done=true;
                cv.notify_all();
                break;
            }
            cv.notify_all();
        }
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        ac = 0;
        done=false;
        result.push_back(startUrl);
        hname = std::move(extractHname(startUrl));
        s.insert(startUrl);
        q.push(startUrl);
        vector<thread> threads;
        for(int i = 0; i<thread::hardware_concurrency();i++){
            threads.emplace_back(thread([&](){worker(htmlParser);}));
        }
        for(auto &x:threads){
            x.join();
        }
        return result;
    }
};