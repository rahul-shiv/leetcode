class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), curr =0, s = 0, t=0;
        for(int i = 0;i<n;i++){
            s+=gas[i]-cost[i];
            t+=gas[i]-cost[i];
            if(s<0){
                curr=i+1;
                s = 0;
            }
        }
        return t>=0?curr:-1;
    }
};