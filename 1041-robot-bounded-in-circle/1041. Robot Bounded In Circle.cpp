class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dirs [][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        int currdir = 0;
        int currx = 0;
        int curry = 0;
        for(auto x:instructions){
            switch(x){
                case 'G':
                    currx+=dirs[currdir][0];
                    curry+=dirs[currdir][1];
                    break;
                case 'L':
                    currdir = (currdir-1+4)%4;
                    break;
                case 'R':
                    currdir = (currdir+1)%4;
                    break;
            }
        }

        return currx==0 and curry==0 or currdir>0;
    }
};