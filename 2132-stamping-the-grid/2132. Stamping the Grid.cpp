class Solution {
    int m,n;
    void calcPrefix2d(vector<vector<int>>& pref2d){
        for(int i = 0;i<m;i++){
            for(int j =0;j<n;j++){
                if(i){
                    pref2d[i][j]+=pref2d[i-1][j];
                }
                if(j){
                    pref2d[i][j]+=pref2d[i][j-1];
                }
                if(i and j){
                    pref2d[i][j]-=pref2d[i-1][j-1];
                }
            }
        }
    }
    int sum2d(int i1,int j1,int i2,int j2, vector<vector<int>>& grid){
        int l=0,o=0,u=0;
        if(j1){
            l = grid[i2][j1-1];
        }
        if(i1){
            u = grid[i1-1][j2];
        }
        if(i1 and j1){
            o = grid[i1-1][j1-1];
        }
        return grid[i2][j2]-l-u+o;
    }
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<int>> pref2d = grid;
        calcPrefix2d(pref2d);
        vector<vector<int>> stamps(m,vector<int>(n));
        for(int i = stampHeight-1;i<m;i++){
            for(int j = stampWidth-1;j<n;j++){
                if(sum2d(i-stampHeight+1,j-stampWidth+1,i,j,pref2d)==0){
                    stamps[i][j]+=1;
                }
            }
        }
        calcPrefix2d(stamps);
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(!grid[i][j] and sum2d(i,j,min(m-1,i+stampHeight-1),min(n-1,j+stampWidth-1),stamps)==0){
                    return false;
                }
            }
        }
        return true;
    }
};