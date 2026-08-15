/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<vector<int>> flat;
        for(auto x: schedule){
            for(auto k:x){
                flat.push_back({k.start,k.end});
            }
        }
        sort(flat.begin(),flat.end());
        vector<Interval> ans;
        int prev = flat[0][0];
        for(auto x:flat){
            if(prev<x[0]){
                ans.emplace_back(Interval(prev,x[0]));
            }
            prev=max(prev,x[1]);
        }
        return ans;
    }
};