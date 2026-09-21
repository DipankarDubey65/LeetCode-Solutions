class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int total = m*n;
        int cs = 0;
        int rs =0;
        int ce = m-1;
        int re=n-1;
        int count=0;
        while(count<total){
            //right
            for(int i=rs;i<=ce;i++){
                ans.push_back(matrix[rs][i]);
                count++;
            }rs++;

            //down
            for(int i=rs;i<=re && count<total;i++){
                ans.push_back(matrix[i][ce]);
                count++;
            }ce--;
            //left
            for(int i=ce;i>=cs && count<total;i--){
                ans.push_back(matrix[re][i]);
                count++;
            }re--;
            //up
            for(int i=re;i>=rs && count<total;i--){
                ans.push_back(matrix[i][cs]);
                count++;
            }cs++;
        }
        return ans;
        
    }
};