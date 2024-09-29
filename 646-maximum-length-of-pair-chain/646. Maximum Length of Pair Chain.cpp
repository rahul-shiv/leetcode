class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int> lis;
        for(auto p:pairs){
            auto it = lower_bound(lis.begin(),lis.end(),p[0]);
            if(it==lis.end()){
                lis.push_back(p[1]);
            }else{
                *it = min(*it,p[1]);
            }
        }
        return lis.size();
    }
};