class HitCounter {
        deque<pair<int,int>> m;
        int total;
public:
    HitCounter() {
        total = 0;
    }

    void hit(int timestamp) {
        if(!m.empty() and m.back().first==timestamp){
            m.back().second+=1;
        }else{
            m.emplace_back(make_pair(timestamp,1));
        }
        total+=1;
    }
    
    int getHits(int timestamp) {
        for(auto &x:m){
            if(x.first>timestamp-300)break;
            total-=x.second;
            m.erase(m.begin());
        }

        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */