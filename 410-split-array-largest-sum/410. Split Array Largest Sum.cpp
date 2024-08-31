class Solution {
    bool isPossible(int lim, vector<int>& nums, int k){
        auto it = nums.begin();
        int s = 0;
        for(int i = 0; i < k; i++){
            if(i){
                if(it!=nums.begin())it--;
                else return false;
                s = *it;
            }
            it = upper_bound(it,nums.end(), s+lim);
        }
        return it==nums.end();
    }
public:
    int splitArray(vector<int>& nums, int k) {
        uint64_t l = 0, r, m;
        for(int i = 1; i <nums.size();i++) nums[i]+=nums[i-1];
        r = nums.back();
        while(l<r){
            m = l + (r-l)/2;
            if(isPossible(m, nums, k)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return r;
    }
};

//7,10
//2,5,8