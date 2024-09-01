class Solution {
    vector<int> p;
public:
    Solution(vector<int>& w) {
        p.push_back(w[0]);
        for(int i = 1; i < w.size();i++){
            p.push_back(p.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int r = rand()%(p.back());
        auto it = upper_bound(p.begin(),p.end(),r);
        return it-p.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */