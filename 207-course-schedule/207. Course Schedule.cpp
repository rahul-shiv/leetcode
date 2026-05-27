class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> g(numCourses);
        queue<int> q;
        for(auto p:prerequisites){
            indegree[p[0]]++;
            g[p[1]].push_back(p[0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!indegree[i]) q.push(i);
        }
        int u;
        while(!q.empty()){
            u = q.front();
            numCourses--;
            q.pop();
            for(auto v:g[u]){
                indegree[v]--;
                if(!indegree[v]){
                    q.push(v);
                }
            }
        }
        return !numCourses;
    }
};