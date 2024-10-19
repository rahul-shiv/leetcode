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
    unordered_set<string> s;
    bool done;
    string extractHname(string & url){
        size_t pos = string("http://").size();
        pos = url.find('/', pos);
        if (pos == string::npos) {
            return url;
        }
        return url.substr(0, pos);
    }

    void worker(HtmlParser htmlParser){
        while(true){
            unique_lock<mutex> guard(m);
            cv.wait(guard,[this](){
                return !q.empty() or done;
            });
            if(q.empty() and done) break;
            string url = q.front();
            q.pop();
            ac++;
            guard.unlock();
            cv.notify_one();
            for(auto v:htmlParser.getUrls(url)){
                string vhname = std::move(extractHname(v));
                if(vhname!=hname)continue;
                unique_lock<mutex> lock(m);
                if(!s.contains(v)){
                    s.insert(v);
                    q.push(v);
                }
                cv.notify_one();
            }
            guard.lock();
            ac--;
            if(ac==0 and q.empty()){
                done=true;
                cv.notify_all();
                break;
            }
        }
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        ac = 0;
        done=false;
        hname = std::move(extractHname(startUrl));
        s.insert(startUrl);
        q.push(startUrl);
        int tc = thread::hardware_concurrency();
        vector<thread> threads(tc);
        for(auto &x:threads){
            x = thread([&](){worker(htmlParser);});
        }
        for(auto &x:threads){
            x.join();
        }
        return vector<string>(s.begin(),s.end());
    }
};