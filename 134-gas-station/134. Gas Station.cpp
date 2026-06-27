class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), s = 0, d = 0, e =0;
        while(s<n){
            while(e < s+n and d>=0){
                d += gas[e%n]-cost[(e)%n];
                e++;
            }
            if(d<0){
                d = 0;
                s = e;
            }
            if(e==s+n)return s;
        }
        return -1;
    }
};