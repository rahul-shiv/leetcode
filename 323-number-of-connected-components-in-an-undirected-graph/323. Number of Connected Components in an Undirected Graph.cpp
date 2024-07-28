class Solution {
    vector<int> id,sz;
    int find(int x){
        if(x==id[x])return x;
        return id[x]=find(id[x]);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        id = vector<int>(n);
        sz = vector<int>(n,1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            id[i]=i;
        }
        for(auto e:edges){
            int a = find(e[0]);
            int b = find(e[1]);
            if(a==b)continue;
            if(sz[a]>sz[b]){
                swap(e[0],e[1]);
                swap(a,b);
            }
            id[a]=b;
            sz[b]+=sz[a];
            find(e[0]);
        }
        for(int i = 0; i < n; i++){
            if(id[i]==i)ans++;
        }
        return ans;
    }
};