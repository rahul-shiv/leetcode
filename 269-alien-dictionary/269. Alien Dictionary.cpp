class Solution {
    unordered_map<char,unordered_set<char>> m;
    unordered_map<char,int> indegree;
    int n;
public:
    int buildGraph(vector<string>& words){
        for(int i =0;i<words.size()-1;i++){
            for(int j = 0; j<words[i].length(); j++){
                indegree[words[i][j]];
            }
            int j;
            for(j = 0; j<min(words[i].length(),words[i+1].length()); j++){
                if(words[i][j]!=words[i+1][j]){
                    auto x = m[words[i][j]].insert(words[i+1][j]);
                    if(x.second) indegree[words[i+1][j]]+=1;
                    break;
                }
            }
            if(j==words[i+1].length() and words[i].length()>words[i+1].length()) return -1;
        }
        for(int j = 0; j<words[words.size()-1].length(); j++){
            indegree[words[words.size()-1][j]];
        }
        return 0;
    }
    string alienOrder(vector<string>& words) {
        n = words.size();
        int t = buildGraph(words);
        if(t)return "";
        queue<char> q;
        for(auto &x:indegree){
            if(x.second==0){
                q.push(x.first);
            }
        }
        string ans ="";
        while(!q.empty()){
            char curr = q.front();
            ans+=curr;
            q.pop();
            for(auto v:m[curr]){
                if(indegree[v]){
                    indegree[v]--;
                    if(!indegree[v]){
                        q.push(v);
                    }
                }
            }
        }
        return ans.length()==indegree.size()?ans:"";
    }
};