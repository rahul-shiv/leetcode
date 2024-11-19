class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> x;
        x[0]=-1;
        int curr = 0;
        for(int i = 0;i<nums.size();i++){
            curr+=nums[i];
            curr%=k;
            auto it = x.find(curr);
            if(it!=x.end()){
                if(i-it->second>1)return true;
            }else{
                x[curr]=i;
            }
        }

        return false;
    }
};