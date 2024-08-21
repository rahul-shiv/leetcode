class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans = grid[0];
        for(int j = 1; j < n; j++) ans[j]+=ans[j-1];
        for(int i = 1; i < m; i++){
            ans[0]+=grid[i][0];
            for(int j = 1; j < n; j++){
                ans[j] = min(ans[j],ans[j-1]) + grid[i][j];
            }
        }
        return ans[n-1];
    }
};