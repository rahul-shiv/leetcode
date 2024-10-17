class SparseVector {
    map<int,int> m;
public:
    
    SparseVector(vector<int> &nums) {
        for(int i = 0;i<nums.size();i++){
            if(nums[i]){
                m[i]=nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        map<int,int> &m2 = vec.m;
        auto it = m.begin(),it2=m2.begin();
        int ans=0;
        while(it!=m.end() and it2!=m2.end()){
            if(it->first<it2->first){
                it++;
            }else if(it->first>it2->first){
                it2++;
            }else{
                ans += it->second*it2->second;
                it++;
                it2++;
            }
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);