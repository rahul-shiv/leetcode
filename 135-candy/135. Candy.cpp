class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), ans = 0;
        if(n==1)return 1;
        vector<int> v(n,1);
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i< n; i++){
            pq.push({-ratings[i],i});
        }
        pair<int,int> x;
        while(!pq.empty()){
            x = move(pq.top());
            pq.pop();
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