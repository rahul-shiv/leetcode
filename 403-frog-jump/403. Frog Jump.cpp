class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return false;
        unordered_map<int,set<int>> m;
        m[0].insert(0);
        int n = stones.size();
        for(int i = 0; i < n;i++){
            auto it = m.find(stones[i]);
            if(it!=m.end()){
                for(auto x:it->second){
                    if(x-1>0){
                        m[it->first+x-1].insert(x-1);
                    }
                    if(x)m[it->first+x].insert(x);
                    m[it->first+x+1].insert(x+1);
                }
            }
        }
        auto it = m.find(stones.back());
        return it!=m.end();
    }
};