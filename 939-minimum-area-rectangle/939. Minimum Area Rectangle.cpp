class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<int,set<int>> xm,ym;
        for(auto &point:points){
            xm[point[0]].insert(point[1]);
            ym[point[1]].insert(point[0]);
        }
        int ans = INT_MAX,t;
        for(int i = 0; i < 2; i++){
            for(auto &y:ym){
                if(y.second.size()>1){
                    auto yit1 = y.second.begin();
                    auto yit2 = yit1;
                    yit2++;
                    //xit are essentially y coordinates and points that exist on the same x axis
                    //yit are essentially x coordinates and points that exist on the same y axis
                    //check if xit2 exists on xm[yit2]
                    while(yit2!=y.second.end()){
                        auto xit1 = xm[*yit1].begin();
                        auto xmend = xm[*yit1].end();
                        while(xit1!=xmend){
                            auto xit2 = xm[*yit2].find(*xit1);
                            if(xit2!=xm[*yit2].end()){
                                t = abs(*yit1-*yit2)*abs(y.first-*xit1);
                                if(t>0){
                                    ans = min(ans, t);
                                }
                            }
                            xit1++;
                        }
                        yit1++;
                        yit2++;
                    }
                }
            }
            swap(xm,ym);
        }
        return ans==INT_MAX?0:ans;;
    }
};