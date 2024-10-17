class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        int k = nums.size();
        for(int i = 0; i < k; i++){
            for(int j = 0; j < nums[i].size(); j++){
                v.push_back({nums[i][j],i});
            }
        }
        sort(v.begin(),v.end());
        vector<int> pres(k);
        vector<int> ans;
        int l = 0, r= 0, n = v.size();
        while(r<n){
            if(!pres[v[r].second]){
                k--;
            }
            pres[v[r].second]++;
            r++;
            while(k==0 and l<r){
                if(ans.empty()){
                    ans.push_back(v[l].first);
                    ans.push_back(v[r-1].first);
                }else if((ans[1]-ans[0])>(v[r-1].first-v[l].first)){
                    ans[0]=v[l].first;
                    ans[1]=v[r-1].first;
                }
                pres[v[l].second]--;
                if(!pres[v[l].second])k++;
                l++;
            }
        }
        return ans;
    }
};