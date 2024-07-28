class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1, i = 0;
        while(i<=r){
            if(nums[i]==0){
                while(l<i and nums[l]==0)l++;
                swap(nums[l],nums[i]);
                if(l==i)i++;
            }else if(nums[i]==2){
                while(r>i and nums[r]==2)r--;
                swap(nums[r],nums[i]);
                if(r==i)i++;
            }else{
                i++;
            }
        }
    }
};