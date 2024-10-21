class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> p2 = people;
        sort(p2.begin(),p2.end());
        vector<int> ans(people.size());
        unordered_map<int,int> pmap;
        map<int,int> fmap;
        fmap[0]=0;
        for(auto flower:flowers){
            fmap[flower[0]]+=1;
            fmap[flower[1]+1]-=1;
        }
        auto it = fmap.begin();
        int tot = 0;
        for(auto person:p2){
            while(it!=fmap.end() and it->first<=person){
                tot+=it->second;
                it++;
            }
            pmap[person]=tot;
        }
        for(int i = 0;i<people.size();i++){
            ans[i]=pmap[people[i]];
        }
        return ans;
    }
};