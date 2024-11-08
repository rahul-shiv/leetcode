#define ll long long
class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        if(m==1)return *max_element(points[0].begin(),points[0].end());
        long long ans = 0;
        vector<long long> lmax(n),rmax(n),curr(n);
        lmax[0]=points[0][0];
        rmax[n-1]=points[0][n-1];
        for(int i = 1; i < n; i++){
            lmax[i]=max(lmax[i-1]-1,(ll)points[0][i]);
            rmax[n-i-1]=max(rmax[n-i]-1,(ll)points[0][n-i-1]);
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                curr[j]=max(lmax[j],rmax[j])+points[i][j];
            }
            lmax[0]=curr[0];
            rmax[n-1]=curr[n-1];
            for(int j = 1; j < n; j++){
                lmax[j]=max(lmax[j-1]-1,curr[j]);
                rmax[n-j-1]=max(rmax[n-j]-1,curr[n-j-1]);
            }
        }
        return *max_element(curr.begin(),curr.end());
    }
};