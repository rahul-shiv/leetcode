class Solution {
    vector<int> id,sz;
    int find(int x){
        if(x==id[x])return x;
        return id[x]=find(id[x]);
    }
    void onion(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a==b)return;
        if(sz[a]<sz[b])swap(a,b);
        id[b]=a;
        sz[a]+=sz[b];
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        sz = vector<int>(n,1);
        id = vector<int>(n);
        map<string,int> a2i;
        for(int i = 0; i < n; i++){
            id[i]=i;
            for(int j = 1; j<accounts[i].size(); j++){
                auto it = a2i.find(accounts[i][j]);
                if(it==a2i.end()){
                    a2i[accounts[i][j]]=i;
                }else{
                    onion(it->second,i);
                }
            }
        }
        vector<vector<string>> ans;
        vector<int> i2a(n,-1);
        int pos;
        for(auto a2i_it:a2i){
            pos = find(a2i_it.second);
            if(i2a[pos]==-1){
                i2a[pos] = ans.size();
                ans.push_back({accounts[pos][0]});
                
            }
            ans[i2a[pos]].push_back(a2i_it.first);
        }

        return ans;
    }
};