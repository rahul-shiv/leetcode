class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        for(int i = 1; i < m; i++){
            matrix[i][0] += min(matrix[i-1][0],matrix[i-1][1]);
            matrix[i][m-1] += min(matrix[i-1][m-2], matrix[i-1][m-1]);
            for(int j = 1; j < m-1; j++){
                matrix[i][j] += min(min(matrix[i-1][j-1],matrix[i-1][j]),matrix[i-1][j+1]);
            }
        }
        return *min_element(matrix[m-1].begin(), matrix[m-1].end());
    }
};