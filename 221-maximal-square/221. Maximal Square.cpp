class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> v(m,vector<int>(n));
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j]=='1'){
                    if(i and j){
                        v[i][j] = min(v[i-1][j-1], min(v[i-1][j],v[i][j-1]))+1;
                    } else {
                        v[i][j]=1;
                    }
                    ans = max(ans,v[i][j]);
                }
            }
        }
        return ans*ans;
    }
};