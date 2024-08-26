/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
    int find(BinaryMatrix &binaryMatrix, int i, int l, int r){
        int m;
        while(l<r){
            m = l+(r-l)/2;
            if(binaryMatrix.get(i,m)==1){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l;
    }
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0];
        int n = binaryMatrix.dimensions()[1];
        int ans = n;
        for(int i = 0; i < m; i++){
            int x = find(binaryMatrix,i,0,ans);
            ans = min(ans,x);
        }
        return ans==n?-1:ans;
    }
};