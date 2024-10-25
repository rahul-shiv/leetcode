class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        int mc = 0, maxc=0;
        for(auto &task:tasks){
            m[task]++;
            if(m[task]>mc){
                mc=m[task];
                maxc=1;
            }else if(m[task]==mc){
                maxc++;
            }
        }
        return max((mc-1)*(n+1)+maxc,(int)tasks.size());
    }
};