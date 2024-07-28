class Solution {
    unordered_map<int,int> m;
    unordered_map<int,int> sz;
    int find(int x){
        if(x==m[x])return x;
        return m[x]=find(m[x]);
    }
    int union_(int x, int y){
        int a = find(x);
        int b = find(y);
        if(a==b)return sz[a];
        if(sz[a]>sz[b]){
            swap(x,y);
            swap(a,b);
        }
        sz[b]+=sz[a];
        m[a]=b;
        find(x);
        return sz[b];
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = !nums.empty();
        for(auto num:nums){
            auto it = m.find(num);
            if(it==m.end()){
                m[num]=num;
                sz[num]=1;
            }
            it = m.find(num-1);
            if(it!=m.end()){
                ans = max(ans,union_(num,num-1));
            }
            it = m.find(num+1);
            if(it!=m.end()){
                ans = max(ans,union_(num,num+1));
            }
        }
        return ans;
    }
};