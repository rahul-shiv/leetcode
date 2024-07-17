class Solution {
    vector<vector<int>> dp;
    int m,n;
    int solve(vector<vector<int>>& matrix, int i, int j){
        int dirs[][2]={{0,1},{1,0},{-1,0},{0,-1}};
        int x,y,ret = 1;
        for(auto dir:dirs){
            x = i+dir[0];
            y = j+dir[1];
            #define check(x,y) x>=0 and y>=0 and x<m and y<n
            if(check(x,y) and matrix[i][j]>matrix[x][y]){
                if(dp[x][y]){
                    ret = max(ret, dp[x][y]+1);
                }else{
                    ret = max(ret,solve(matrix,x,y)+1);
                }
            }
        }
        dp[i][j]=ret;
        return ret;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int ans = 1;
        dp = vector<vector<int>>(m,vector<int>(n));
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(!dp[i][j]){
                    ans = max(ans,solve(matrix,i,j));
                }
            }
        }
        return ans;
    }
};