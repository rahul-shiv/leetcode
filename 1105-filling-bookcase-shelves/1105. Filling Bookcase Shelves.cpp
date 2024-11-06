class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        int w,h;
        unordered_map<int,int> m;
        m[-1]=0;
        for(int i = 0;i<n;i++){
            w = h = 0;
            m[i]=INT_MAX;
            for(int j=i;j>=0;j--){
                w+=books[j][0];
                if(w>shelfWidth)break;
                h=max(h,books[j][1]);
                m[i] = min(m[i],m[j-1]+h);
            }
        }
        return m[n-1];
    }
};