
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis = vector<vector<bool>>(m,vector<bool>(n));
        int x,y,d,nx,ny;
        int dirs[][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<tuple<int,int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j]=='*'){
                    q.push({i,j,0});
                    vis[i][j]=1;
                    break;
                }
            }
            if(!q.empty())break;
        }
        while(!q.empty()){
            tie(x,y,d) = q.front();
            q.pop();
            for(auto dir:dirs){
                nx = x+dir[0];
                ny = y+dir[1];
                #define check(a,b) a>=0 and a<m and b>=0 and b<n
                if(check(nx,ny) and grid[nx][ny]!='X' and !vis[nx][ny]){
                    if(grid[nx][ny]=='#'){
                        return d+1;
                    }else{
                        vis[nx][ny]=1;
                        q.push({nx,ny,d+1});
                    }
                }
            }
        }
        return -1;
    }
};