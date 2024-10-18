class HitCounter {
        vector<pair<int,int>> m;
public:
    HitCounter() {
        m.emplace_back(make_pair(0,0));
    }
    
    void clearOld(int timestamp){
        auto it = upper_bound(m.begin(),m.end(),make_pair(timestamp-300,INT_MAX));
        if(it!=m.begin()){
            it--;
            m.erase(m.begin(),it);
        }
    }

    void hit(int timestamp) {
        clearOld(timestamp);
        if(m.empty()){
            m.emplace_back(make_pair(timestamp,0));
        }else{
            m.emplace_back(make_pair(timestamp,m.back().second+1));
        }
    }
    
    int getHits(int timestamp) {
        clearOld(timestamp);
        auto it = m.begin();
        auto it2 = m.end();
        if(it2==m.begin()){return 0;}
        it2--;
        if(it==it2 and it->first>timestamp-300){
            cout<<it2->second<<endl;
            return it2->second;
        }else{
            cout<<it2->second-it->second<<endl;
            return it2->second-it->second;
        }
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */