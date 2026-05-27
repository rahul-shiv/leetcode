class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> g(n);
        vector<int> in(n);
        queue<int> q;
        int vis=0;
        for(auto &x:pre){
            g[x[1]].push_back(x[0]);
            in[x[0]]++;
        }
        for(int i = 0;i <n;i++) if(!in[i])q.push(i);
        while(!q.empty()){
            vis++;
            int k = q.front();
            q.pop();
            for(auto next:g[k]){
                if(--in[next]==0){
                    q.push(next);
                }
            }
        }
        return vis==n;
    }
};