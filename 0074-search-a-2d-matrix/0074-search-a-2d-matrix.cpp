class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =  matrix.size();
        int m = matrix[0].size();
        int l=0;
        int h =n-1;
        int row =0;
        while(l<=h){
            int mid = l+(h-l)/2;
            if(matrix[mid][0]<=target){
                row = mid;
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        int s=0;
        int e = m-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return false;

    }
};