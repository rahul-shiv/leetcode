class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> m;
        for(auto x:tasks){
            m[x]++;
        }
        set<pair<int,char>,greater<pair<int,char>>> s;
        int ans = 0;
        map<int,int> q;
        for(auto k:m){
            q[k.second]++;
        }
        return max((q.rbegin()->first-1)*(n+1)+q.rbegin()->second,(int)tasks.size());
    }
};