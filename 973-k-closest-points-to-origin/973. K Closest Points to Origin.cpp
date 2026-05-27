class Solution {
    #define DIST(point) (point[0] * point[0] + point[1] * point[1])

    void threeWayPartition(vector<vector<int>>& points, int l, int r, int& lt, int& gt) {
        int pivotDist = DIST(points[r]);
        lt = l;
        gt = r;
        int i = l;
        
        while (i <= gt) {
            if (DIST(points[i]) < pivotDist) {
                swap(points[i++], points[lt++]);  // Move points less than pivot to the left
            } else if (DIST(points[i]) > pivotDist) {
                swap(points[i], points[gt--]);  // Move points greater than pivot to the right
            } else {
                i++;  // Move to the next element if it's equal to the pivot
            }
        }
    }

    void quickSelect(vector<vector<int>>& points, int l, int r, int k) {
        int lt, gt;
        while (l < r) {
            int piv = rand() % (r - l + 1) + l;  // Randomly select a pivot
            swap(points[r], points[piv]);
            threeWayPartition(points, l, r, lt, gt);

            if (k < lt) {
                r = lt - 1;  // Continue in the left partition
            } else if (k > gt) {
                l = gt + 1;  // Continue in the right partition
            } else {
                return;  // k is within the range of points equal to the pivot
            }
        }
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        srand(time(nullptr));
        quickSelect(points, 0, points.size() - 1, k - 1);
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
