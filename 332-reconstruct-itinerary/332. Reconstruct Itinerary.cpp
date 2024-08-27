class Solution {
    vector<string> ans;
    unordered_map<string,multiset<string>> m;
    int n;
public:
    bool solve(string curr){
        if(ans.size()==n){
            return true;
        }
        bool t = false;
        auto it = m[curr].begin();
        while(it!=m[curr].end()){
            auto next = *it;
            m[curr].erase(it);
            ans.push_back(next);
            t = solve(next);
            if(t)break;
            ans.pop_back();
            it = m[curr].insert(next);
            it++;
        }
        return t;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        n = tickets.size()+1;
        for(auto ticket:tickets){
            m[ticket[0]].insert(ticket[1]);
        }
        ans.push_back("JFK");
        solve("JFK");
        return ans;
    }
};