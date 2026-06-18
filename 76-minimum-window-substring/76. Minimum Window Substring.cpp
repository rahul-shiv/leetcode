class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        int notvalid=0;
        for(auto c:t){
            m[c]++;
            if(m[c]==1)notvalid++;
        }
        deque<int> q;
        int cnt = t.length();
        string ans=s;
        int i=0;
        while(i<s.length()){
            // find next letter
            while(i<s.length()){
                auto it = m.find(s[i]);
                i++;
                if(it!=m.end()){
                    q.push_back(i-1);
                    it->second--;
                    if(it->second==0)notvalid--;
                    break;
                }
            }
            // squeeze till still valid
            while(!notvalid and m[s[q.front()]]<0){
                m[s[q.front()]]++;
                q.pop_front();
            }
            // save
            if(!notvalid and ans.length()>(i-q.front())){
                ans=s.substr(q.front(),i-q.front());
            }
        }
        return notvalid?"":ans;
    }
};