class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x = -1, r= nums.size()-1;
        for(int i = r;i>0;i--){
            if(nums[i]>nums[i-1]){
                x = i-1;
                for(int j = r; j>x;j--){
                    if(nums[j]>nums[x]){
                        swap(nums[j],nums[x]);
                        break;
                    }
                }
                break;
            }
        }
        reverse(nums.begin()+x+1, nums.end());
    }
};