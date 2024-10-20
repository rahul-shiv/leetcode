class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        map<int,int> m;
        m[0]=0;
        for(auto day:days){
            auto it = prev(m.upper_bound(day-1));
            m[day] = it->second+costs[0];
            it = prev(m.upper_bound(day-7));
            m[day] = min(it->second+costs[1],m[day]);
            it = prev(m.upper_bound(day-30));
            m[day] = min(it->second+costs[2],m[day]);
        }
        return m[days.back()];
    }
};