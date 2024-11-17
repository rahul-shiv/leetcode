/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l = 0, r = mountainArr.length()-1, m;
        while(l<r){
            m = l+(r-l)/2;
            if(mountainArr.get(m)>mountainArr.get(m+1)){
                r=m;
            }else{
                l=m+1;
            }
        }
        int p =l;
        l = 0;
        if(target<=mountainArr.get(p) and target>=mountainArr.get(l)){
            r = p;
            while(l<=r){
                m = l+(r-l)/2;
                if(mountainArr.get(m)==target)return m;
                else if(mountainArr.get(m)<target)l=m+1;
                else r=m-1;
            }
        }
        r = mountainArr.length()-1;
        if(target>=mountainArr.get(r) and target<mountainArr.get(p)){
            l=p+1;
            while(l<=r){
                m = l+(r-l)/2;
                if(mountainArr.get(m)==target)return m;
                else if(mountainArr.get(m)>target)l=m+1;
                else r=m-1;
            }
        }
        return -1;
    }
};