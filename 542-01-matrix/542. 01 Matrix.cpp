class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,1e4));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j]){
                    if(i){
                        ans[i][j] = min(ans[i][j],ans[i-1][j]+1);
                    }
                    if(j){
                        ans[i][j] = min(ans[i][j],ans[i][j-1]+1);
                    }
                }else{
                    ans[i][j]=0;
                }
            }
        }
        for(int i = m-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(mat[i][j]){
                    if(i<m-1){
                        ans[i][j] = min(ans[i][j],ans[i+1][j]+1);
                    }
                    if(j<n-1){
                        ans[i][j] = min(ans[i][j],ans[i][j+1]+1);
                    }
                }else{
                    ans[i][j]=0;
                }
            }
        }
        return ans;
    }
};