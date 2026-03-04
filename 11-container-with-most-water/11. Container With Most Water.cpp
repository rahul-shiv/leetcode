class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<int> l(n),r(n);
        l[0]=height[0];
        r[n-1]=height[n-1];
        for(int i = 1; i < n; i++){
            l[i]=max(l[i-1],height[i]);
            r[n-i-1]=max(r[n-i],height[n-i-1]);
        }
        int i = 0, j = n-1, ans = min(l[0],r[n-1])*(n-1);
        while(i<j){
            if(l[i]>r[j]){
                j--;
            }else{
                i++;
            }
            ans = max(ans,min(l[i],r[j])*(j-i));
        }
        return ans;
    }
};