class Solution {
public:
    int ansCalculate(vector<vector<int>>&matrix,int k,int guess){
        int n = matrix.size();
        int m = matrix[0].size();
        int r = n-1;
        int c = 0;
        int count=0;
        
        while(r>=0 && c<m){
            if(matrix[r][c]>guess){
                r--;
            }
            else{
                count += r+1;
                c++;
                
            }
        }
        return count;

    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size()-1;
        int m = matrix[0].size()-1;
        int res = -1;

        int l =matrix[0][0];
        int h = matrix[n][m];

        while(l<=h){
            int guess= l+(h-l)/2;           
            int ans= ansCalculate(matrix,k,guess);
            if(ans<k){
                l = guess+1;
            }
            else{
                res = guess;
                h = guess-1;
            }
           
        }
        return res;
    }
};