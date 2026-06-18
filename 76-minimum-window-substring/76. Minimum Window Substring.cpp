class Solution {
public:
    string minWindow(string s, string t) {
        string ans,x;
        queue<int> q;
        vector<int> m(128,-1);
        vector<queue<int>> cq(128);
        int req = t.size();
        for(auto c:t){
            if(m[c]==-1){
                m[c]=0;
            }
            m[c]+=1;
        }
        int i = 0, n = s.size(),start=0,end=0;
        for(; i < n; i++){
            if(m[s[i]]!=-1){
                if(cq[s[i]].size()<m[s[i]]){
                    req--;
                }else{
                    cq[s[i]].pop();
                }
                cq[s[i]].push(i);
                q.push(i);

                while(!q.empty() and !cq[s[q.front()]].empty() and cq[s[q.front()]].front()>q.front()){
                    q.pop();
                }
                if(!req and !end or (i-q.front())<(end-start)){
                    start=q.front();
                    end=i;
                }
            }
        }
        if(!req) ans = s.substr(start,end+1-start);
        return ans;
    }
};