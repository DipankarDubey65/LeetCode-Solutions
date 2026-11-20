class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int totalSize = n*m;
        int s =0;
        int e = totalSize-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            int col = mid%m;
            int row = mid/m;
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]<target){
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return false;
    }
};