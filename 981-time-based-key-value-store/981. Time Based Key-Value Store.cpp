class TimeMap {
    unordered_map<string,map<int,string>> m;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto it = m.find(key);
        if(it==m.end())return "";
        auto it2 = it->second.upper_bound(timestamp);
        if(it2==it->second.begin())return "";
        it2--;
        return it2->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */