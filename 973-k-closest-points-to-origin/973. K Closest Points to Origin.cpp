class Solution {
    int dist(vector<int> &x){
        return x[0]*x[0]+x[1]*x[1];
    }
    int partition(vector<vector<int>>& nums, int l, int r){
        int t = rand()%(r-l+1)+l;
        swap(nums[r],nums[t]);
        int p = l;
        int x = dist(nums[r]);
        for(int i = l; i<r;i++){
            if(dist(nums[i])<=x){
                swap(nums[p++],nums[i]);
            }
        }
        swap(nums[r],nums[p]);
        return p;
    }
    void qsort(vector<vector<int>>& points, int k, int l, int r){
        if(l>=r or r<l)return;
        int p = r;
        while(p!=k){
            p = partition(points,l,r);
            if(p==k)return;
            else if(p<k) l=p+1;
            else r=p-1;
        }
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        qsort(points,k-1,0,points.size()-1);
        vector<vector<int>> ans(points.begin(),points.begin()+k);
        return ans;
    }
};