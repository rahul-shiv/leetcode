class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int,int>,greater<>> s;
        vector<int> ans; 
        for(int i = 0;i<k-1;i++){
            s.insert({nums[i],i});
        }
        for(int i = k-1;i<nums.size();i++){
            s.insert({nums[i],i});
            while(s.begin()->second<i-k+1)s.erase(s.begin());
            ans.push_back(s.begin()->first);
        }
        return ans;
    }
};