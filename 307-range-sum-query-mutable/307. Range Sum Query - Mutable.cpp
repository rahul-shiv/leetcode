class NumArray {
    vector<int> bit;
    vector<int> nums;
    #define LSB(x) (x&-x)
    void construct(){
        for(int i = 1; i<=bit.size();i++){
            int x = i + LSB(i);
            if(x<bit.size()){
                bit[x]+=bit[i];
            }
        }
    }

    int prefixSum(int i){
        int sum = 0;
        while(i){
            sum+=bit[i];
            i -= LSB(i);
        }
        return sum;
    }
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        bit.push_back(0);
        bit.insert(bit.begin()+1,nums.begin(),nums.end());
        construct();
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        index+=1;
        while(index<bit.size()){
            bit[index]+=diff;
            index += LSB(index);
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum(right+1)-prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */