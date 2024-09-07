class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> v;
        int x = 0;
        priority_queue<int> pq;
        for(int i = 0; i< n; i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        while(x<n and v[x].first<=w){
            pq.push(v[x++].second);
        }
        while(k-- and !pq.empty()){
            w+=pq.top();
            pq.pop();
            while(x<n and v[x].first<=w){
                pq.push(v[x++].second);
            }
        }
        return w;
    }
};