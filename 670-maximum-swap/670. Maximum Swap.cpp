class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int i,m=0,swaps=0,t;
        while(m<s.length() and !swaps){
            t = m;
            for(i = m+1;i<s.length();i++){
                if(s[i]>=s[t]){
                   t = i;
                }
            }
            if(t!=m and s[t]!=s[m]){
                swap(s[t],s[m]);
                swaps++;
            }
            m++;
        }
        return stoi(s);
    }
};