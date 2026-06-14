class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0, m = grid.size(), n = grid[0].size(), cnt=0;
        queue<tuple<int,int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==2) q.push({i,j,0});
                else if(grid[i][j]==1)cnt++;
            }
        }
        if (cnt==0)return 0;
        int dirs[][2] = {{0,1},{1,0},{-1,0},{0,-1}}, x,y,nx,ny,level;
        while(!q.empty()){
            tie(x,y,level)=q.front();
            ans = max(ans,level);
            q.pop();
            for(auto dir:dirs){
                nx = x+dir[0]; ny = y+dir[1];
                if(nx>=0 and ny>=0 and nx<m and ny<n and grid[nx][ny]==1){
                    cnt--;
                    grid[nx][ny]=2;
                    q.push({nx,ny,level+1});
                }
            }
        }
        return cnt==0?ans:-1;
    }
};