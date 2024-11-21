class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        vector<char> v(s.begin(),s.end());
        int i = v.size()-2;
        while(i>=0){
            if (v[i]<v[i+1]){
                int j = i+1, k = i+1;
                while(j<v.size()){
                    if(v[j]>v[i] and v[j]<=v[k]){
                        k=j;
                    }
                    j++;
                }
                swap(v[i],v[k]);
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