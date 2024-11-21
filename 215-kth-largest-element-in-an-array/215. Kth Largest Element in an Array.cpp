class Solution {
    void partition(vector<int>& nums, int &lt, int&gt, int l , int r){
        int piv = nums[r];
        lt = l; gt = r;
        int i = l;
        while(i<=gt){
            if(nums[i]>piv){
                swap(nums[i++],nums[lt++]);
            }
            else if(nums[i]<piv){
                swap(nums[i],nums[gt--]);
            }else{
                i++;
            }
        }
    }
    void topk(vector<int>& nums, int k, int l , int r){
        int lt, gt;
        while(l<r){
            int pivot = rand()%(r-l+1)+l;
            swap(nums[r],nums[pivot]);
            partition(nums, lt,gt,l,r);
            if(k<lt){
                r = lt-1;
            } else if(k>gt){
                l = gt+1;
            }else{
                return;
            }
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        topk(nums,k-1,0,nums.size()-1);
        return nums[k-1];
    }
};