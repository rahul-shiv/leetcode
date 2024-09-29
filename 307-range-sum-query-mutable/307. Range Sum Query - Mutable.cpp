class NumArray {
    vector<int> bit;
    vector<int> nums;
    #define LSB(x) x&(-x)
    void construct(){
        bit = vector<int>(nums.size()+1);
        for(int i = 0; i<nums.size();i++){
            add(i+1,nums[i]);
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
    void add(int index, int val){
        while(index<bit.size()){
            bit[index]+= val;
            index += LSB(index);
        }
    }
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        construct();
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        index+=1;
        add(index,diff);
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