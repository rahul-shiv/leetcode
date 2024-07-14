class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int k1 = k;
        auto it = lower_bound(arr.begin(),arr.end(),x);
        if(it==arr.begin()){
            ans = vector<int>(arr.begin(),arr.begin()+k);
            return ans;
        }
        int r = distance(arr.begin(),it);
        int l = r-1;
        while(k and r!=arr.size() and l!=-1){
            k--;
            if(abs(arr[r]-x)<abs(arr[l]-x)){
                r++;
            }else{
                l--;
            }
        }
        while(k and l!=-1){
            k--;
            l--;
        }
        while(k and r!=arr.size()){
            r++;
            k--;
        }
        ans = vector<int>(arr.begin()+(r-k1),arr.begin()+r);
        return ans;
    }
};