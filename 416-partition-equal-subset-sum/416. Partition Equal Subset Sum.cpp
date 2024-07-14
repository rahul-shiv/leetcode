class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s%2)return false;
        bitset<10001> isPossible(1);
        for(auto num:nums){
            isPossible |= isPossible<<num;
        }
        return isPossible[s/2];
    }
};