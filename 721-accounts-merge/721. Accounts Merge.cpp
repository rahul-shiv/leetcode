class Solution {
    int n;
    vector<int> id;
    vector<int> size;
    map<string,int> a2i;
    vector<string> names;
public:
    int find(int x){
        while(x!=id[x]){
            id[x]=id[id[x]];
            x = id[x];
        }
        return x;
    }
    int merge(int a, int b){
        int x = find(a);
        int y = find(b);
        if(x!=y){
            if(size[y]>size[x])swap(x,y);
            size[x]+=size[y];
            id[y]=x;
        }
        return x;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        n = accounts.size();
        id.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)id[i]=i;
        for(auto account:accounts){
            names.push_back(account[0]);
            int j = names.size()-1;
            int x = find(j);
            for(int i =1;i<account.size();i++){
                auto it = a2i.find(account[i]);
                if(it!=a2i.end()){
                    x = merge(x,find(it->second));
                    id[j] = x;
                }
                a2i[account[i]] = x;
            }
        }
        map<int,vector<string>> i2s;
        for(auto a:a2i){
            int x = find(a.second);
            i2s[x].push_back(a.first);
        }
        vector<vector<string>> ans;
        for(auto x:i2s){
            vector<string> temp;
            temp.push_back(names[x.first]);
            for(auto y:x.second) temp.push_back(y);
            ans.push_back(temp);
        }
        return ans;
        
    }
};