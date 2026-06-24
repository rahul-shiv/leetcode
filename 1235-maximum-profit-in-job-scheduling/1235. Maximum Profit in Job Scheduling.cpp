class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
        vector<pair<int, pair<int,int>>>times;
        for(int i=0;i<startTime.size();i++){
            times.push_back({endTime[i], {startTime[i], profit[i]}});
            
        }
        sort(times.begin(), times.end());
        map<int,int> dp;
        
        for(auto time:times){
            
            //for each time
            // - we need val of previous end time lesser than end time
            // - we need val of previous end time <= start time of us 

            auto it = dp.lower_bound(time.first);
            if(it!=dp.begin()){
                it--;
                dp[time.first] = max(dp[time.first],it->second);
            }
            it = dp.upper_bound(time.second.first);
            int x = 0;
            if(it!=dp.begin()){
                it--;
                x = it->second;
            }
            dp[time.first] = max(dp[time.first],x+time.second.second);
            // cout << time.first << " "<< dp[time.first] << endl;
            // dp[time.first] = max(dp[time.first],max(it->second+time.second.second);
        }
        return dp.rbegin()->second;
    }
};