class LFUCache {
    unordered_map<int,pair<int,list<pair<int,int>>::iterator>> m;
    unordered_map<int,list<pair<int,int>>> c;
    int capacity;
    int count;
    int minf;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
        minf = 0;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it==m.end())return -1;
        int val = it->second.first;
        auto lit = it->second.second;
        lit->second++;
        c[lit->second].splice(c[lit->second].end(),c[lit->second-1],lit);
        if(lit->second-1==minf and c[lit->second-1].empty())minf=lit->second;
        return val;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it==m.end()){
            if(count==capacity){
                int t = c[minf].front().first;
                c[minf].erase(c[minf].begin());
                m.erase(t);
            }else{
                count++;
            }
            c[1].push_back({key,1});
            m[key]={value,prev(c[1].end())};
            minf = 1;
        }else{
            it->second.first = value;
            auto lit = it->second.second;
            lit->second++;
            c[lit->second].splice(c[lit->second].end(),c[lit->second-1],lit);
            if(lit->second-1==minf and c[lit->second-1].empty())minf=lit->second;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */