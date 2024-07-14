class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> x(m,vector<int>(n));
        int ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j]=='1'){
                    x[i][j]=1;
                    if(i and j) x[i][j] = min(x[i-1][j-1],min(x[i][j-1],x[i-1][j]))+1;
                    ans = max(ans,x[i][j]);
                }
            }
        }
        return ans*ans;
    }
};