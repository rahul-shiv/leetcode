class FindSumPairs {
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    vector<int> &mapping;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2): mapping(nums2) {
        for(auto num:nums1){
            m1[num]++;
        }
        for(auto num:nums2){
            m2[num]++;
        }
    }
    
    void add(int index, int val) {
        m2[mapping[index]]--;
        mapping[index]+=val;
        m2[mapping[index]]+=1;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto x:m1){
            ans+=x.second*m2[tot-x.first];
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