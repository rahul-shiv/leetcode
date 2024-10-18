class Solution {
public:
    int compress(vector<char>& chars) {
        int l = 0, r = 0, n = chars.size(),cnt=0, ret = 0;
        while(r<n){
            while(r<n and chars[r]==chars[l]){
                r++;
                cnt++;
            }
            chars[ret++]=chars[l];
            if(cnt>1){
                for(auto x:to_string(cnt)){
                    chars[ret++]=x;
                }
            }
            cnt=0;
            l=r;
        }
        return ret;
    }
};