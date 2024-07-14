class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        auto it = upper_bound(arr.begin(),arr.end(),x);
        if(it==arr.begin()){
            ans = vector<int>(arr.begin(),arr.begin()+k);
            return ans;
        }
        auto it2=it;
        it2--;
        while(k and it!=arr.end()){
            k--;
            if(abs(*it-x)<abs(*it2-x)){
                ans.push_back(*it);
                it++;
            }else{
                ans.push_back(*it2);
                if(it2==arr.begin())break;
                it2--;
            }
        }
        while(k and it!=arr.end()){
            ans.push_back(*it);
            it++;
            k--;
        }
        while(k){
            k--;
            ans.push_back(*it2);
            if(it2==arr.begin())break;
            it2--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};