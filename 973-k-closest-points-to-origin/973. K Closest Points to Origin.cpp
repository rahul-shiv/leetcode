class Solution {
    #define DIST(point) (point[0]*point[0]+point[1]*point[1])
    int partition(vector<vector<int>>& points, int l, int r){
        for(int i = l; i<r;i++){
            if(DIST(points[i])<DIST(points[r])){
                swap(points[i],points[l++]);
            }
        }
        swap(points[r],points[l]);
        return l;
    }
    void kClosest(vector<vector<int>>& points, int l, int r,int k){
        int piv;
        while(l<r){
            piv = rand()%(r-l)+l;
            swap(points[r],points[piv]);
            piv = partition(points,l,r);
            if(piv>k){
                r = piv-1;
            }else if (piv<k){
                l = piv+1;
            }else{
                return;
            }
        }
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        srand(time(nullptr));
        vector<vector<int>> ans;
        kClosest(points,0,points.size()-1,k-1);
        ans = vector<vector<int>>(points.begin(),points.begin()+k);
        return ans;
    }
};