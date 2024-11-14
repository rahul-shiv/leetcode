class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans; 
        for(int i = 0;i<k-1;i++){
            while(!q.empty() and nums[q.back()]<nums[i])q.pop_back();
            q.push_back(i);
        }
        for(int i = k-1;i<nums.size();i++){
            while(!q.empty() and q.front()<i-k+1)q.pop_front();
            while(!q.empty() and nums[q.back()]<nums[i])q.pop_back();
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
        //redo with monotonic dequeue
    }
};