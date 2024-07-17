class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> q;
        vector<int> ans; 
        for(int i = 0;i<k-1;i++){
            while(!q.empty() and q.back().first<nums[i])q.pop_back();
            q.push_back({nums[i],i});
        }
        for(int i = k-1;i<nums.size();i++){
            while(!q.empty() and q.front().second<i-k+1)q.pop_front();
            while(!q.empty() and q.back().first<nums[i])q.pop_back();
            q.push_back({nums[i],i});
            ans.push_back(q.front().first);
        }
        return ans;
        //redo with monotonic dequeue
    }
};