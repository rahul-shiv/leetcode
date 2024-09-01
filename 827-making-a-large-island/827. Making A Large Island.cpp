class Solution {
    vector<int> id,sz;
    int find(int x){
        if(id[x]==x)return x;
        return id[x]=find(id[x]);
    }
    void uni(int i, int j){
        int u,v;
        u = find(i);
        v = find(j);
        if(u==v)return;
        if(sz[u]<sz[v]){
            swap(i,j);
            swap(u,v);
        }
        id[v]=id[u];
        sz[u]+=sz[v];
        find(j);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int dirs[][2]={{0,1},{1,0},{0,-1},{-1,0}};
        id.reserve(n*n);
        sz = vector<int>(n*n,0);
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                id.push_back(i*n+j);
                if(grid[i][j])sz[i*n+j]=1;
            }
        }
        int x,y,p;
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j]){
                    x = i-1;
                    y = j;
                    if(i and grid[x][y]){
                        uni(i*n+j,x*n+y);
                    }
                    x = i;
                    y = j-1;
                    if(j and grid[x][y]){
                        uni(i*n+j,x*n+y);
                    }
                }
            }
        }
        #define check(x,y) x>=0 and x<n and y>=0 and y<n and grid[x][y]
        int ans = *max_element(sz.begin(),sz.end());
        for(int i = 0; i < n;i++){
            for(int j = 0; j < n;j++){
                if(!grid[i][j]){
                    unordered_set<int> s;
                    int temp = 1;
                    for(auto dir:dirs){
                        x = i+dir[0];
                        y = j+dir[1];
                        if(check(x,y)){
                            p = find(x*n+y);
                            auto it = s.find(id[p]);
                            if(it==s.end()){
                                s.insert(id[p]);
                                temp+=sz[p];
                            }
                        }
                    }
                    ans = max(ans,temp);
                }
            }
        }
        return ans;
    }
};