class LRUCache {
    list<int> l;
    unordered_map<int,pair<int,list<int>::iterator>> m;
    int capacity;
public:
    LRUCache(int capacity): capacity(capacity) {
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it==m.end()){
            return -1;
        }
        // l.erase(it->second.second);
        // l.push_back(key);
        // it->second.second = prev(l.end());
        l.splice(l.end(),l,it->second.second);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it==m.end()){
            if(l.size()==capacity){
                m.erase(l.front());
                l.pop_front();
            }
            l.push_back(key);
            m[key] = make_pair(value,prev(l.end()));
        }else{
            it->second.first = value;
            l.splice(l.end(),l,it->second.second);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */