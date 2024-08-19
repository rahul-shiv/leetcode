class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int currh = -1;
        vector<vector<int>> ans;
        multiset<int> s;
        vector<tuple<int,int,int>> v;
        for(auto b:buildings){
            v.push_back({b[0],b[2],0});
            v.push_back({b[1],b[2],1});
        }
        sort(v.begin(),v.end(),[](auto const &a, auto const &b){
            if (std::get<0>(a) != std::get<0>(b)) {
                return std::get<0>(a) < std::get<0>(b);
            } else if (std::get<1>(a) != std::get<1>(b)) {
                return std::get<1>(a) > std::get<1>(b);
            } else {
                return std::get<2>(a) < std::get<2>(b);
            }
        });
        int h, i, type;
        for(auto point:v){
            tie(i,h,type)=point;
            if(type){
                s.erase(s.lower_bound(h));
                if(s.empty()){
                    currh=0;
                    if(!ans.empty() and i==ans.back()[0])ans.back()[1]=currh;
                    else ans.push_back({i,0});
                }else{
                    currh=*s.rbegin();
                    if(currh<h){
                        if(!ans.empty() and i==ans.back()[0])ans.back()[1]=currh;
                        else ans.push_back({i,currh});
                    }
                }
            }else{
                if(h>currh){
                    currh=h;
                    if(!ans.empty() and i==ans.back()[0])ans.back()[1]=currh;
                    else ans.push_back({i,h});
                }
                s.insert(h);
            }
        }
        return ans;
    }
};