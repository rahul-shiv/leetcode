class Solution {
    tuple<int,int,int> extract(string &log){
        int id = 0, type=0, time=0;
        for(auto c:log){
            if(type){
                if(isdigit(c)){
                    time=time*10+c-'0';
                }
            }else{
                if(isdigit(c)){
                    id=id*10+c-'0';
                }else if(c=='s'){
                    type=1;
                }else if(c=='e'){
                    type=2;
                }
            }
        }
        return {id,type,time};
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int,int>> s;
        int id, type, time;
        for(auto log:logs){
            tie(id,type,time) = extract(log);
            if(type==1){
                if(!s.empty())ans[s.top().first]+=time-s.top().second;
                s.push({id,time});
            }else{
                ans[id]+=time-s.top().second+1;
                s.pop();
                if(!s.empty())s.top().second=time+1;
            }
        }
        return ans;
    }
};