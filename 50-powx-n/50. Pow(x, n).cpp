class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        if(x==0)return 0;
        if(n<0){x=1/x;}
        double t = 1;
        while(n){
            if(n%2){
                t *= x;
            }
            x*=x;
            n = abs(n/2);
        }
        return t;
    }
};