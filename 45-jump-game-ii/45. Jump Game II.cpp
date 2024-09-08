class Solution {
public:
    int jump(vector<int>& nums) {
        queue<pair<int,int>> q;
        int n = nums.size();
        vector<int>vis(n,INT_MAX); 
        vis[0]=0;
        int m = 1;
        for(int i = 0; i < n; i++){
            for(; m<n and m<=i+nums[i];m++){
                vis[m]=vis[i]+1;
            }
            if(n==m)break;
        }
        
        return vis[n-1];
    }
};