class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses);
        vector<int> ans;
        queue<int> q;
        for(auto p:prerequisites){
            g[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }
        for(int i = 0; i<numCourses;i++){
            if(!indegree[i])q.push(i);
        }
        int u;
        while(!q.empty()){
            u = q.front();
            q.pop();
            ans.push_back(u);
            numCourses--;
            for(auto v:g[u]){
                indegree[v]--;
                if(!indegree[v])q.push(v);
            }
        }
        if(numCourses)return {};
        return ans;
    }
};