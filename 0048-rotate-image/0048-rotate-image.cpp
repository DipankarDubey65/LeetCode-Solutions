class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      int  nrows =matrix.size();
       int ncol = matrix[0].size();

        //step 1 Transpose
        for(int i =0; i<nrows;i++){
            for(int j= i; j<ncol;j++){
                swap(matrix[i][j],matrix[j][i]);
            }

        }
        // step 2 reverse row wise matrix
        for(int i=0;i<nrows;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }


    }
};