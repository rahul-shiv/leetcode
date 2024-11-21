class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        vector<char> v(s.begin(),s.end());
        int i = v.size()-2;
        while(i>=0){
            if (v[i]<v[i+1]){
                int j = v.size()-1;
                while(j>i){
                    if(v[j]>v[i]){
                        break;
                    }
                    j--;
                }
                swap(v[i],v[j]);
                reverse(v.begin()+i+1,v.end());
                int ans = 0;
                for(auto &x:v) {
                    if((long)ans*10>INT_MAX)return -1;
                    ans*=10;
                    if((long)ans+(x-'0')>INT_MAX)return -1;
                    ans+=(x-'0');
                }
                return ans;
            }
            i--;
        }
        return -1;
    }
};