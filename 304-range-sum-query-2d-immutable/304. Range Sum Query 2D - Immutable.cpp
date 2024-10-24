class NumMatrix {
    vector<vector<int>> summat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        summat = matrix;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(j){
                    summat[i][j]+=summat[i][j-1];
                }
            }
            if(i){
                for(int j = 0; j < matrix[0].size(); j++){
                    summat[i][j]+=summat[i-1][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int s = summat[row2][col2];
        if(row1-1>=0){
            s-=summat[row1-1][col2];
        }
        if(col1-1>=0){
            s-=summat[row2][col1-1];
        }
        if(row1-1>=0 and col1-1>=0){
            s+=summat[row1-1][col1-1];
        }
        return s;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */