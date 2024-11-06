class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        int m = cuts.size(),x,y;
        vector<vector<int>> ans(m,vector<int>(m));
        for(int l = 1;l<=cuts.size();l++){
            for(int i = 0;i<=m-l;i++){
                int j = i+l-1;
                x=0;
                y=n;
                if(i) x =cuts[i-1];
                if(j<m-1) y = cuts[j+1];
                ans[i][j]=y-x;
                if(l>1){
                    int t= min(ans[i+1][j],ans[i][j-1]);
                    for(int k = i;k<=j-2;k++){
                        t = min(t,ans[i][k]+ans[k+2][j]);
                    }
                    ans[i][j]+=t;
                }
            }
        }
        return ans[0].back();
    }
};

