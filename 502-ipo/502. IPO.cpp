class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        map<int,priority_queue<int>> m;
        priority_queue<pair<int,int>> pq;
        for(int i = 0; i < n; i++){
            m[capital[i]].push(profits[i]);
        }
        auto it = m.lower_bound(0);
        while(it!=m.end()){
            if(it->first>w)break;
            pq.push({it->second.top(),it->first});
            it->second.pop();
            it++;
        }
        while(k-- and !pq.empty()){
            auto x = pq.top();
            pq.pop();
            auto it = m.find(x.second);
            if(!it->second.empty()){
                pq.push({it->second.top(),it->first});
                it->second.pop();
            }
            it = m.upper_bound(w);
            while(it!=m.end()){
                if(it->first>w+x.first)break;
                pq.push({it->second.top(),it->first});
                it->second.pop();
                it++;
            }
            w+=x.first;
        }
        return w;
    }
};