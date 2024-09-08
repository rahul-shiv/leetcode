class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        if(n==1)return 1;
        vector<int> v(n,1);
        vector<pair<int,int>> arr;
        for(int i = 0; i< n; i++){
            arr.push_back({ratings[i],i});
        }
        sort(arr.begin(),arr.end());
        for(auto &x:arr){
            if(x.second and ratings[x.second]>ratings[x.second-1]){
                v[x.second] = v[x.second-1]+1;
            }
            if(x.second<n-1 and ratings[x.second]>ratings[x.second+1]){
                v[x.second] = max(v[x.second],v[x.second+1]+1);
            }
            ans+=v[x.second];
        }
        return ans;
    }
};