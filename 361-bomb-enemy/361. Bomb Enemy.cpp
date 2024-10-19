class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<int,int>>> g(m,vector<pair<int,int>>(n));
        int ans = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]=='E'||grid[i][j]=='0'){
                    int e = grid[i][j]=='E';
                    if(i){
                        g[i][j].first = g[i-1][j].first+e;
                    }else{
                        g[i][j].first = e;
                    }
                    if(j){
                        g[i][j].second = g[i][j-1].second+e;
                    }else{
                        g[i][j].second = e;
                    }
                }
            }
        }
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                if(grid[i][j]=='E'||grid[i][j]=='0'){
                    if(i<m-1)g[i][j].first=max(g[i+1][j].first,g[i][j].first);
                    if(j<n-1)g[i][j].second=max(g[i][j+1].second,g[i][j].second);
                    
                }
                if(grid[i][j]=='0'){
                    ans = max(ans,g[i][j].first+g[i][j].second);
                }
            }
        }
        return ans;
    }
};