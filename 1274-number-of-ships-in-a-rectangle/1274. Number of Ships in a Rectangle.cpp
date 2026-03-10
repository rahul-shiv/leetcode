/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> tr, vector<int> bl) {
        int xmin = bl[0], xmax = tr[0], ymin = bl[1], ymax = tr[1],
            xh = (xmin + xmax) / 2, yh = (ymin + ymax) / 2;
        if (xmin>xmax or ymin>ymax or !sea.hasShips(tr, bl)) return 0;
        if (tr == bl) {
            return 1;
        }
        int ans = 0;
        ans += countShips(sea, {xh, ymax}, {xmin, yh+1}); // TL
        ans += countShips(sea, {xmax, ymax}, {xh+1, yh+1}); // TR
        ans += countShips(sea, {xh, yh}, {xmin, ymin}); // BL
        ans += countShips(sea, {xmax, yh}, {xh+1, ymin}); // BR
        return ans;
    }
};