class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<uint64_t,int>,vector<pair<uint64_t,int>>,greater<pair<uint64_t,int>>> pq;
        pair<uint64_t,int> p;
        set<int> s;
        uint64_t d;
        int ans = 0;
        vector<int> v(n);
        for(int i = 0; i <n;i++){
            s.insert(i);
        }
        for(auto m:meetings){
            d = 0;
            while(!pq.empty() and m[0]>=pq.top().first){
                p = pq.top();
                pq.pop();
                s.insert(p.second);
            }
            if(pq.size()==n){
                p = pq.top();
                pq.pop();
                d=max((uint64_t)0,p.first-m[0]);
                s.insert(p.second);
            }
            auto it = s.begin();
            pq.push({m[1]+d,*it});
            v[*it]++;
            if(v[*it]>v[ans]){
                ans=*it;
            }else if(v[*it]==v[ans]){
                ans = min(*it,ans);
            }
            s.erase(it);
        }
        return ans;
    }
};