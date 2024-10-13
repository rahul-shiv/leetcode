class FindSumPairs {
    unordered_map<int,int> m2;
    vector<int> &nums1,&nums2;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums1(nums1), nums2(nums2) {
        for(auto num:nums2){
            m2[num]++;
        }
    }
    
    void add(int index, int val) {
        m2[nums2[index]]--;
        nums2[index]+=val;
        m2[nums2[index]]+=1;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto num:nums1){
            ans+=m2[tot-num];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */