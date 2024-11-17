class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int lcol = 0,rcol=n-1;
        while(lcol<=rcol){
            int mcol = lcol + (rcol-lcol)/2;
            int maxi=0;
            for(int i = 0;i<m;i++){
                if(mat[i][mcol]>mat[maxi][mcol]){
                    maxi=i;
                }
            }
            if(mcol and mat[maxi][mcol]<mat[maxi][mcol-1])rcol=mcol-1;
            else if(mcol<n-1 and mat[maxi][mcol]<mat[maxi][mcol+1])lcol=mcol+1;
            else return {maxi,mcol};
        }
        return {-1,-1};
    }
};