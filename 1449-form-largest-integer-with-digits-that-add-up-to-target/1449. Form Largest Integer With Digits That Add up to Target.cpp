class Solution {
    int comp(const string& num1, string num2) {
    if (num1.length() < num2.length()) {
        return -1; 
    }
    if (num1.length() > num2.length()) {
        return 1; 
    }

    for (size_t i = 0; i < num1.length(); ++i) {
        if (num1[i] < num2[i]) {
            return -1; 
        }
        if (num1[i] > num2[i]) {
            return 1; 
        }
    }

    return 0;
}
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> ans(target+1,"-1");
        ans[target]="0";
        for(int i = 8; i>=0;i--){
            for(int j = target;j-cost[i]>=0;j--){
                string t = "";
                if(ans[j]!="0") t =ans[j];
                if(ans[j]=="-1")continue;
                if(ans[j-cost[i]]=="-1"){
                    ans[j-cost[i]]=t+to_string(i+1);
                }
                else if(comp(ans[j-cost[i]],t+to_string(i+1))<0){
                    ans[j-cost[i]]=t+to_string(i+1);
                }
            }
        }

        return ans.front()=="-1"?"0":ans.front();
    }
};