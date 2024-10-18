class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        vector<int> ans(n+1,INT_MAX);
        sq.push_back(1);
        ans[0]=0;
        for(int i = 1;i<=n;i++){
            if((sq.back()+1)*(sq.back()+1)==i){
                sq.push_back(sq.back()+1);
            }
            for(auto s:sq){
                ans[i]=min(ans[i],ans[i-s*s]+1);
            }
        }
        return ans[n];
    }
};