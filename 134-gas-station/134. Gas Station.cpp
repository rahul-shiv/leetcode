class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(),g = gas[0],s=0;
        for(int i = 1; i < 2*n;i++){
            g = g - cost[(i-1)%n];
            if(g<0){
                s = i;
                g = 0;
            }
            if(i-s==n)return s;
            g+=gas[i%n];
        }
        return -1;
    }
};