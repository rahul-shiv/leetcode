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
        vector<Interval> schedules;
        for(auto s:schedule){
            for(auto x:s){
                schedules.push_back(x);
            }
        }      
        sort(schedules.begin(),schedules.end(),[](const auto &a, const auto &b){
            return a.start==b.start?a.end<b.end:a.start<b.start;
        });
        vector<Interval> mi;
        vector<Interval> ans;
        for(auto x:schedules){
            if(mi.empty()|| mi.back().end<x.start){
                mi.push_back(x);
            }else{
                mi.back().end=max(mi.back().end,x.end);
            }
        }
        for(int i = 1;i<mi.size();i++){
            ans.emplace_back(Interval(mi[i-1].end,mi[i].start));
        }
        return ans;
    }
};