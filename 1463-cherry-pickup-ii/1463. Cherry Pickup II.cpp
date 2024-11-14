class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<map<pair<int,int>,int>> g(m);
        g[0][{0,n-1}]=grid[0][0]+grid[0][n-1];
        int dirs[][2] = {{0,1},{1,0},{0,0},{1,1},{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1}};
        for(int i = 1;i<m;i++){
            for(auto &p:g[i-1]){
                for(auto &dir:dirs){
                    int r1 = p.first.first+dir[0];
                    int r2 = p.first.second+dir[1];
                    #define CHECK(x,y) r1>=0 and r2<n and r2>=0 and r2<n and r1<=r2
                    if(CHECK(r1,r2)){
                        auto it = g[i].find({r1,r2});
                        if(it==g[i].end()){
                            g[i][{r1,r2}]=p.second+grid[i][r1]+(r1!=r2)*grid[i][r2];
                            ans = max(ans,g[i][{r1,r2}]);
                        }else{
                            it->second = max(it->second, p.second+grid[i][r1]+(r1!=r2)*grid[i][r2]);
                            ans = max(ans,it->second);
                        }
                    }
                }
            }
        }

        return ans;
    }
};