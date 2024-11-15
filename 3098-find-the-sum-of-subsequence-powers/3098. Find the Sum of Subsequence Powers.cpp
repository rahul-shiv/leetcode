#define MOD 1000000007
class Solution {
    int n;
    unordered_map<int, unordered_map<int,unordered_map<int,int>>> m;
    int solve(vector<int>& nums,int i, int mindiff, int k){
        if(!k)return mindiff;
        if(i==n)return 0;
        if(m.contains(i) and m[i].contains(k) and m[i][k].contains(mindiff)){
            return m[i][k][mindiff];
        }
        int ans = 0;
        int t;
        for(int j=i;j<n;j++){
            t = mindiff;
            if(i)t =min(mindiff,nums[j]-nums[i-1]);
            ans = (ans+solve(nums,j+1,t,k-1)%MOD)%MOD;
        }
        return m[i][k][mindiff]=ans;
    }
public:
    int sumOfPowers(vector<int>& nums, int k) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        return solve(nums, 0, nums[n-1]-nums[0],k);
    }
};
