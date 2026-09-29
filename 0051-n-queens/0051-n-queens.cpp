class Solution {
public:
unordered_map<int,bool>rowCheck;
unordered_map<int,bool>LowerDigonalCheck;
unordered_map<int,bool>UpperDigonalCheck;

 void storeSolution(vector<vector<string>>&ans,vector<vector<char>>&board,int n){
    vector<string>TempAns;
    for(int i=0;i<n;i++){
        string output = "";
        for(int j=0;j<n;j++){
            output.push_back(board[i][j]);
        }
        //string is ready
        TempAns.push_back(output);
    }

    ans.push_back(TempAns);
 }

 bool isSafe(int row,int col,vector<vector<char>>&board){

    //check for row
    if(rowCheck[row]==true){
        //not safe
        return false;
    }
    //check for Lower Digonal
    if(LowerDigonalCheck[row+col]==true){
        //not safe
        return false;
    }
    // check for upper Digonal 
    if(UpperDigonalCheck[row-col]==true){
        //not safe
        return false;
    }
    //safe
    return true;

 }
void solve(int n,vector<vector<char>>&board,vector<vector<string>>&ans,int col){
    //base case
    if(col>=n){
        storeSolution(ans,board,n);
        return;
    }
    //1 case me and onother recursion
    for(int row = 0;row<n;row++){
        if(isSafe(row,col,board)){
            board[row][col] = 'Q';
                 rowCheck[row]=true;
                 LowerDigonalCheck[row+col]=true;
                  UpperDigonalCheck[row-col]=true;


            solve(n,board,ans,col+1);
            //back track bhool jata hu
            board[row][col]= '.';
                 rowCheck[row]=false;
                  LowerDigonalCheck[row+col]=false;
                  UpperDigonalCheck[row-col]=false;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<vector<char>>board(n,vector<char>(n,'.'));
         int col =0;
         solve(n,board,ans,col);

         return ans;

        
    }
};