class Solution {
    vector<int> id, sz;
    int find(int x){
        if(id[x]==x)return x;
        return id[x]=find(id[x]);
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int cnt = 0;
        vector<int> ans;
        id = vector<int>(m*n);
        sz = vector<int>(m*n);
        for(int i = 0; i<m*n; i++) id[i]=i;
        int dirs[][2] = {{0,1},{1,0},{-1,0},{0,-1}}, nx, ny, x, y, k, nk, a, b;
        #define check(x,y) x>=0 and x<m and y>=0 and y<n
        for(auto &pos:positions){
            x = pos[0];
            y = pos[1];
            k = x*n+y;
            if(sz[k]){
                ans.push_back(cnt);
                continue;
            }
            sz[k]=1;
            cnt++;
            for(auto &dir:dirs){
                nx = x+dir[0];
                ny = y+dir[1];
                nk = nx*n + ny;
                if(check(nx,ny) and sz[nk]){
                    a = find(k);
                    b = find(nk);
                    if(a==b)continue;
                    if(sz[a]<sz[b]){
                        swap(a,b);
                    }
                    sz[a]+=sz[b];
                    id[b]=id[a];
                    find(k);
                    find(nk);
                    cnt--;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};