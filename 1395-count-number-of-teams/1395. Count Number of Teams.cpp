class Solution {
public:
    int numTeams(vector<int>& rating) {
        set<int> l,r;
        int n = rating.size(), ans = 0;
        l.insert(rating[0]);
        for(int i = 2;i<n;i++){
            r.insert(rating[i]);
        }
        for(int i = 1;i<n-1;i++){
            auto it = l.lower_bound(rating[i]);
            auto it2 = r.upper_bound(rating[i]);
            auto rit = l.upper_bound(rating[i]);
            auto rit2 = r.lower_bound(rating[i]);
            if(it!=l.begin() and it2!=r.end()){
                it = prev(it);
                ans += (distance(l.begin(),it)+1)*(distance(it2,r.end()));
            }
            if(rit2!=r.begin() and rit!=l.end()){
                rit2 = prev(rit2);
                ans += (distance(r.begin(),rit2)+1)*(distance(rit,l.end()));
            }
            l.insert(rating[i]);
            it2 = r.find(rating[i+1]);
            r.erase(it2);
        }
        return ans;
    }
};