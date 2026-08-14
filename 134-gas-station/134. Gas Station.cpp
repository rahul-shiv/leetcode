class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), k = 0, curr =0, s = 0;
        for(int i = 0;i<2*n;i++){
            s+=gas[i%n];
            if(s-cost[i%n]<0){
                curr = i+1;
                s = 0;
                k = 0;
            }else{
                s-=cost[i%n];
                k++;
                if(k==n)return curr;
            }
        }
        return -1;
    }
};