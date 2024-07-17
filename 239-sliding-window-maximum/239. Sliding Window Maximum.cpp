class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> s;
        vector<int> ans; 
        for(int i = 0;i<k-1;i++){
            s.push({nums[i],i});
        }
        for(int i = k-1;i<nums.size();i++){
            s.push({nums[i],i});
            while(s.top().second<i-k+1)s.pop();
            ans.push_back(s.top().first);
        }
        return ans;
    }
};