class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long ans = 0;
        sort(enemyEnergies.begin(),enemyEnergies.end());
        int l = 0, r = enemyEnergies.size()-1;
        while(l<=r){
            while(currentEnergy>=enemyEnergies[l]){
                ans+=currentEnergy/enemyEnergies[l];
                currentEnergy-=currentEnergy/enemyEnergies[l]*enemyEnergies[l];
            }
            if(ans){
                currentEnergy+=enemyEnergies[r--];
            }
            if(currentEnergy<enemyEnergies[l])break;
        }
        return ans;
    }
};