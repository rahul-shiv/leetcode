#define INF 2147483647
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<tuple<int,int,int>> q;
        int m = rooms.size(), n = rooms[0].size(), x,y,nx,ny,d;
        int dirs[][2] = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!rooms[i][j]){
                    q.push({i,j,0});
                }
            }
        }
        #define check(x,y) x<m and y<n and x>=0 and y>=0 and rooms[x][y]==INF
        while(!q.empty()){
            tie(x,y,d) = q.front();
            q.pop();
            for(auto dir:dirs){
                nx=x+dir[0];
                ny=y+dir[1];
                if(check(nx,ny)){
                    q.push({nx,ny,d+1});
                    rooms[nx][ny]=d+1;
                }
            }
        }
    }
};