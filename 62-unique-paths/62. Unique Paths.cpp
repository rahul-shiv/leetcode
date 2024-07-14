class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> grid(n,1);
        for(int i = 1;i<m;i++){
            for(int j = 0;j<n;j++){
                if(j){
                    grid[j]+=grid[j-1];
                }
            }
        }
        return grid[n-1];
    }
};