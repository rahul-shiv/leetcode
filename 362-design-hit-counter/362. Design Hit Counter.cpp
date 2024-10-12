class HitCounter {
        map<int,int> m;
public:
    HitCounter() {
        m[0]=0;
    }
    
    void clearOld(int timestamp){
        auto it = m.upper_bound(timestamp-300);
        if(it!=m.begin()){
            it--;
            m.erase(m.begin(),it);
        }
    }

    void hit(int timestamp) {
        clearOld(timestamp);
        if(m.empty()){
            m[timestamp]++;
        }else{
            m[timestamp]=m.rbegin()->second+1;
        }
    }
    
    int getHits(int timestamp) {
        clearOld(timestamp);
        auto it = m.begin();
        auto it2 = m.upper_bound(timestamp);
        if(it2==m.begin()){return 0;}
        it2--;
        if(it==it2 and it->first>timestamp-300){
            return it2->second;
        }else{
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