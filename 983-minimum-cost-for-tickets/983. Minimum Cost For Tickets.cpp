class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> ans(days.back()+1,0);
        int it = 0;
        for(int i = 1; i <= days.back(); i++){
            if(i==days[it]){
                ans[i] = min({ans[i - 1] + costs[0],
                               ans[max(0, i - 7)] + costs[1],
                               ans[max(0, i - 30)] + costs[2]});
                it++;
            }else{
                ans[i]=ans[i-1];
            }
        }
        return ans[days.back()];
    }
};