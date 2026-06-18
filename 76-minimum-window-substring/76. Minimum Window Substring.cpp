class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>m(128,INT_MAX);
        int notvalid=0;
        for(auto c:t){
            if(m[c]==INT_MAX)m[c]=1;
            else m[c]++;
            if(m[c]==1)notvalid++;
        }
        deque<int> q;
        int cnt = t.length();
        string ans=s;
        int i=0,l=0,r=INT_MAX-2;
        while(i<s.length()){
            // find next letter
            while(i<s.length()){
                i++;
                if(m[s[i-1]]!=INT_MAX){
                    q.push_back(i-1);
                    m[s[i-1]]--;
                    if(m[s[i-1]]==0)notvalid--;
                    break;
                }
            }
            // squeeze till still valid
            while(!notvalid and m[s[q.front()]]<0){
                m[s[q.front()]]++;
                q.pop_front();
            }
            // save
            if(!notvalid and (r-l+1)>(i-q.front())){
                r=i;
                l=q.front();
            }
        }
        return notvalid?"":s.substr(l,r-l);
    }
};