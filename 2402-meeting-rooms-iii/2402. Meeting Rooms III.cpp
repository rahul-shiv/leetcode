class Solution {
public:
    Solution(){
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<uint64_t,int>,vector<pair<uint64_t,int>>,greater<pair<uint64_t,int>>> pq;
        pair<uint64_t,int> p;
        priority_queue<int> s;
        uint64_t d;
        int ans = 0, room;
        vector<int> v(n);
        for(int i = 0; i <n;i++){
            s.push(-i);
        }
        for(auto m:meetings){
            d = 0;
            while(!pq.empty() and m[0]>=pq.top().first){
                p = pq.top();
                pq.pop();
                s.push(-p.second);
            }
            if(pq.size()==n){
                p = pq.top();
                pq.pop();
                d=max((uint64_t)0,p.first-m[0]);
                s.push(-p.second);
            }
            room = -s.top();
            pq.push({m[1]+d,room});
            v[room]++;
            if(v[room]>v[ans]){
                ans=room;
            }else if(v[room]==v[ans]){
                ans = min(room,ans);
            }
            s.pop();
        }
        return ans;
    }
};