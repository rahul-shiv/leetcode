class Solution {
    uint ipToInt(string ip){
        uint intIp=0;
        string temp;
        stringstream ss(ip);
        getline(ss,temp,'.');
        intIp+= stoi(temp)<<24;
        getline(ss,temp,'.');
        intIp+= stoi(temp)<<16;
        getline(ss,temp,'.');
        intIp+= stoi(temp)<<8;
        getline(ss,temp,'.');
        intIp+= stoi(temp);
        return intIp;
    }
    string intToIp(uint intIp){
        string stringIp;
        stringIp += to_string(intIp>>24)+".";
        stringIp += to_string((intIp>>16)&255)+".";
        stringIp += to_string((intIp>>8)&255)+".";
        stringIp += to_string((intIp)&255);
        return stringIp;
    }
public:
    vector<string> ipToCIDR(string ip, int n) {
        vector<string> ans;
        uint intIp = ipToInt(ip);
        uint mask,maxCount,temp;
        while(n>0){
            maxCount = intIp&-intIp;
            if(maxCount==0) maxCount = 1<<31;
            while(maxCount>n)maxCount>>=1;
            mask=32;
            temp = maxCount;
            while(!(temp&1)){
                temp>>=1;
                mask-=1;
            }
            ans.push_back(intToIp(intIp)+"/"+to_string(mask));
            intIp+=maxCount;
            n-=maxCount;
        }
        return ans;
    }
};