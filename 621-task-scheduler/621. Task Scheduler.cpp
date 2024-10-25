class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(!n)return tasks.size();
        unordered_map<char,int> m;
        for(auto x:tasks){
            m[x]++;
        }
        set<pair<int,char>,greater<pair<int,char>>> s;
        int ans = 0;
        for(auto k:m){
            s.insert({k.second,k.first});
        }
        queue<pair<int,char>> q;
        int l=-1,k;
        while(!s.empty()){
            k = s.size();
            for(int i = 0; i<min(n+1,k);i++){
                auto t = s.begin();
                if(t->first-1){
                    q.push({t->first-1,t->second});
                }
                s.erase(t);
                ans++;
            }
            if(q.size())ans+=max(0,n+1-k);
            while(!q.empty()){
                s.insert(q.front());
                q.pop();
            }
        }
        return ans;
    }
};