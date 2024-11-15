class RandomizedCollection {
    unordered_map<int,unordered_set<int>> m;
    vector<int> v;
public:
    RandomizedCollection() {
        srand(time(0));
    }
    
    bool insert(int val) {
        bool t = !m.contains(val) or m[val].size()==0;
        m[val].insert(v.size());
        v.push_back(val);
        return t;
    }
    
    bool remove(int val) {
        auto it = m.find(val);
        if(it==m.end() or it->second.empty())return false;
        int i = *it->second.begin();
        bool ins = i!=(v.size()-1);
        it->second.erase(i);
        swap(v[i],v.back());
        m[v[i]].erase(v.size()-1);
        v.pop_back();
        if(ins)m[v[i]].insert(i);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */