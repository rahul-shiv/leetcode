class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> indegree(numCourses);
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
            numCourses--;
            for(auto v:g[u]){
                indegree[v]--;
                if(!indegree[v])q.push(v);
            }
        }
        return numCourses!=0?false:true;
    }
};