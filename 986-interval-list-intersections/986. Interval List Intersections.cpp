class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        vector<vector<int>> ans;
        int m = f.size(), n = s.size(),i=0,j=0;
        while(i<m and j<n){
            if(f[i][0]>s[j][1]){
                j++;
            }else if(f[i][1]<s[j][0]){
                i++;
            }else{
                ans.push_back({max(f[i][0],s[j][0]),min(f[i][1],s[j][1])});
                if(f[i][1]<s[j][1]){
                    i++;
                }else if(s[j][1]<f[i][1]){
                    j++;
                }else{
                    i++;
                    j++;
                }
            }
        }
        return ans;
    }
};