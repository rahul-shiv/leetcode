class Solution {
public:
    int minRefuelStops(int target, int startFuel,vector<vector<int>>& stations) {
        if (startFuel >= target)
            return 0;
        sort(stations.begin(), stations.end());
        priority_queue<int> pq;
        int stops = 0, i = 0, n = stations.size();
        while (startFuel<target) {
            for (; i < n; i++) {
                if (startFuel < stations[i][0])
                    break;
                pq.push(stations[i][1]);
            }
            if (pq.empty())
                return -1;
            startFuel += pq.top();
            pq.pop();
            stops++;
        }
        return stops;
    }
};