class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<vector<int>> q;
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]==0)q.push({i,j});
            }
        }
        int dirs[][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            vector<int> curr = q.front();
            q.pop();
            for(auto dir:dirs){
                int x = curr[0]+dir[0], y = curr[1]+dir[1];
                if(x>=0 and x<m and y>=0 and y<n and mat[x][y]!=0 and ans[x][y]==0){
                    q.push({x,y});
                    ans[x][y]=ans[curr[0]][curr[1]]+1;
                }
            }
        }
        return ans;
    }
};