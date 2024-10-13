class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> ans;
        for(int i = 0; i < heights.size();i++){
            while(!ans.empty() and heights[i]>=heights[ans.back()]){
                ans.pop_back();
            }
            ans.push_back(i);
        }
        return ans;
    }
};