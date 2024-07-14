class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int> wc;
        vector<string> ans;
        for(auto word:words){
            wc[word]++;
        }
        map<int,vector<string>> m;
        for(auto w:wc){
            m[-w.second].push_back(w.first);
        }
        for(auto x:m){
            // sort(x.second.begin(),x.second.end());
            ans.insert(ans.end(),x.second.begin(),x.second.begin()+min(x.second.size(),k-ans.size()));
            if(ans.size()>=k)break; 
        }
        return ans;
    }
};