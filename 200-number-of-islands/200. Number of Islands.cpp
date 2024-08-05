class Solution {
    int m,n;
    vector<vector<bool>> vis;
    void dfs(int i, int j, vector<vector<char>>& grid){
        int x, y;
        int dirs[][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        vis[i][j] = 1;
        for(auto dir:dirs){
            x = i + dir[0];
            y = j + dir[1];
            #define check(a,b) (a>=0 and a<m and b>=0 and b<n)
            if(check(x,y) and !vis[x][y] and grid[x][y]=='1'){
                dfs(x,y,grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size(), n = grid[0].size();
        vis = vector<vector<bool>>(m,vector<bool>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    dfs(i,j,grid);
                    ans+=1;
                }
            }
        }
        return ans;
    }
};