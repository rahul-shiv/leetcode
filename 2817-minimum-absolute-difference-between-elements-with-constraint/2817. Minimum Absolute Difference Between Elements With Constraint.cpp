class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        int n = nums.size();
        multiset<int> s;
        for(int i =x;i<n;i++){
            s.insert(nums[i]);
        }
        int ans = INT_MAX;
        for(int i = 0;i<n-x;i++){
            auto it = s.upper_bound(nums[i]);
            if(it!=s.begin()){
                auto it2 = prev(it);
                ans = min(ans,abs(nums[i]-*it2));
            }
            if(it!=s.end()){
                ans = min(ans,abs(nums[i]-*it));
            }
            it = s.find(nums[i+x]);
            s.erase(it);
        }
        return ans;
    }
};