class Solution {
    vector<int> id,sz;
    int find(int x){
        while(x!=id[x]){
            id[x]=id[id[x]];
            x = id[x];
        }
        return id[x];
    }
    void uni(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a,b);
                swap(x,y);
            }
            sz[a]+=sz[b];
            id[b]=id[a];
            find(y);
        }
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string,int> a2i;
        
        int n = accounts.size();
        id = vector<int> (n);
        sz = vector<int> (n,1);
        for(int i = 0; i < n; i++) id[i]=i;

        int ind = 0;
        for(auto account:accounts){
            for(int i = 1; i < account.size(); i++){
                auto it = a2i.find(account[i]);
                if(it==a2i.end()){
                    a2i[account[i]] = ind;
                }else{
                    uni(it->second,ind);
                }
            }
            ind++;
        }
        for(int i = 0; i < n; i++) find(i);

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