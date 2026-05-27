class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(),x,y,nx,ny;
        int dirs[][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i = 0; i<m;i++){
            for(int j = 0; j<n;j++){
                if(!mat[i][j]){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            tie(x,y)=q.front();
            q.pop();
            for(auto dir:dirs){
                nx = x+dir[0];
                ny = y+dir[1];
                if(nx>=0 and nx<m and ny>=0 and ny<n and ans[nx][ny]==-1){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return ans;
    }
};