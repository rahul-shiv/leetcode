class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<int> dp(n*n);
        dp[n-1]=grid[0][0]+grid[0][n-1];
        unordered_set<int> frontier;
        frontier.insert(n-1);
        int dirs[][2] = {{0,1},{1,0},{0,0},{1,1},{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1}};
        for(int i = 1;i<m;i++){
            unordered_set<int> nfrontier;
            vector<int> ndp(n*n);
            for(int x:frontier){
                int t1 = x/n;
                int t2 = x%n;
                for(auto &dir:dirs){
                    int r1 = t1+dir[0];
                    int r2 =t2+dir[1];
                    #define CHECK(x,y) r1>=0 and r2<n and r2>=0 and r2<n and r1<=r2
                    if(CHECK(r1,r2)){
                        ndp[r1*n+r2] = max(ndp[r1*n+r2], dp[t1*n+t2]+grid[i][r1]+(r1!=r2)*grid[i][r2]);
                        ans = max(ans,ndp[r1*n+r2]);
                        nfrontier.insert(r1*n+r2);
                    }
                }
            }
            frontier = move(nfrontier);
            dp = move(ndp);
        }

        return ans;
    }
};