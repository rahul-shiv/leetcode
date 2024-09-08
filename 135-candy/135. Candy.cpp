class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size(), p = 0;
        vector<int> vals(n);
        vals[0]=1;
        for(int i = 1; i < n; i++){
            if(nums[i]>nums[i-1]){
                p = i;
                vals[i]=vals[i-1]+1;
            }else if(nums[i]==nums[i-1]){
                p = i;
                vals[i]=1;
            }else{
                while(i+1<n and nums[i+1]<nums[i])i+=1;
                vals[i]=1;
                for(int j = i-1; j >= p ; j--){
                    if(vals[j]<=vals[j+1])vals[j]=vals[j+1]+1;
                }
            }
        }
        return accumulate(vals.begin(),vals.end(),0);   
    }
};

// 1 2 1 2 1

// 1 2 3 1 3 2 1 