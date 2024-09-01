class Solution {
    vector<int> id,sz;
    int find(int x){
        if(id[x]==x)return x;
        return id[x]=find(id[x]);
    }
    int uni(int x, int y){
        int a,b;
        a = find(x);
        b = find(y);
        if(a==b)return sz[a];
        if(sz[a]<sz[b]){
            swap(x,y);
            swap(a,b);
        }
        sz[a]+=sz[b];
        id[b]=id[a];
        find(y);
        return sz[a];
    }
public:
    int earliestAcq(vector<vector<int>>& logs, int n) {
        sz = vector<int>(n,1);
        id.reserve(n);
        sort(logs.begin(),logs.end());
        for(int i = 0; i < n; i++) id.push_back(i);
        for(auto log:logs){
            if(uni(log[1],log[2])==n){
                return log[0];
            }
        }
        return -1;
    }
};