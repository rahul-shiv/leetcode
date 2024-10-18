class Solution {
public:
    double myPow(double x, int n) {
        if(n==1||x==1)return x;
        if(n==0)return 1;
        if(x==0)return 0;
        if(n<0){x=1/x;}
        if(n%2){
            return x*myPow(x*x,abs(n/2));
        }else{
            return myPow(x*x,abs(n/2));
        }
    }
};