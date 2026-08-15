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
        int prev = -1;
        vector<Interval> ans;
        int c=0;
        vector<int> starts;
        vector<int> ends;

        for(int i = 0; i<schedule.size();i++){
            for(auto s:schedule[i]){
                starts.push_back(s.start);
                ends.push_back(s.end);
            }
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        int s = 0, e = 0, n = starts.size();
        while(s<n){
            while(ends[e]<starts[s]){prev=ends[e];e++;}
            if(e==s and prev!=-1) ans.push_back(Interval(prev,starts[s]));
            s++;
        }
        return ans;
    }
};