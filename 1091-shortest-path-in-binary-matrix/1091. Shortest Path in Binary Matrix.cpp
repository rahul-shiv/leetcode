class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        if(grid[m-1][n-1]||grid[0][0])return -1;
        vector<vector<int>>vis(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=1;
        int i,j,ni,nj;
        int dirs[][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};
        #define check(x,y) (x>=0 and x<m and y>=0 and y<n and grid[x][y]==0 and vis[x][y]==INT_MAX)
        while(!q.empty()){
            tie(i,j)=q.front();
            q.pop();
            for(auto dir:dirs){
                ni=i+dir[0];
                nj=j+dir[1];
                if(check(ni,nj)){
                    vis[ni][nj]=vis[i][j]+1;
                    q.push({ni,nj});
                }
            }
        }
        return vis[m-1][n-1]==INT_MAX?-1:vis[m-1][n-1];
    }
};