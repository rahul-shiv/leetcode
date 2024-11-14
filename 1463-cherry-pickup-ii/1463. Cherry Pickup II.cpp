class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<vector<int>>> v(m,vector<vector<int>>(n,vector<int>(n)));
        v[0][0][n-1]=grid[0][0]+grid[0][n-1];
        vector<unordered_set<int>> frontier(m);
        frontier[0].insert(n-1);
        int dirs[][2] = {{0,1},{1,0},{0,0},{1,1},{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1}};
        for(int i = 1;i<m;i++){
            for(int x:frontier[i-1]){
                int t1 = x/n;
                int t2 = x%n;
                for(auto &dir:dirs){
                    int r1 = t1+dir[0];
                    int r2 =t2+dir[1];
                    #define CHECK(x,y) r1>=0 and r2<n and r2>=0 and r2<n and r1<=r2
                    if(CHECK(r1,r2)){
                        v[i][r1][r2] = max(v[i][r1][r2], v[i-1][t1][t2]+grid[i][r1]+(r1!=r2)*grid[i][r2]);
                        ans = max(ans,v[i][r1][r2]);
                        frontier[i].insert(r1*n+r2);
                    }
                }
            }
        }

        return ans;
    }
};