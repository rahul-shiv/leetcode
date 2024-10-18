class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> v(n+1),temp;
        int ans = 0,x;
        for(auto row:matrix){
            for(int i = 0; i < n; i++){
                if(row[i]=='1'){
                    v[i]+=1;
                }else{
                    v[i]=0;
                }
            }
            temp = v;
            stack<int> s;
            for(int i = 0; i<n+1;i++){
                x = i;
                while(!s.empty() and temp[s.top()]>temp[i]){
                    x = s.top();
                    s.pop();
                    ans = max(ans, temp[x]*(i-x));
                    temp[x]=temp[i];
                }
                s.push(x);
            }
        }
        return ans;
    }
};