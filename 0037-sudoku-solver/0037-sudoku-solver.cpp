class Solution {
public:
   bool isSafe(char digit,int row,int col,vector<vector<char>>&board){
    //3 rule
    //rowCheck
    int n = board.size();
    for(int k=0;k<n;k++){
        if(board[row][k]== digit){
            // same digit phle se same row me exist krta hai
            return false;

        }
        
    }
    //col check
    for(int k=0;k<n;k++){
        if(board[k][col]== digit){
            //same col me same digit exist krti hai
            return false; 
        }

    }
    // 3*3 sub array check
    for(int k=0;k<n;k++){
        if(board[3*(row/3)+k/3][3*(col/3)+k%3]==digit){
            return false;
        }

    }
    return true;


   }
   bool solve(vector<vector<char>>&board){
    //entire logic
    //base case


    //1 case i wil solve and onother case recursion will solve

    // first of all find the empty cell
    // empty ->'.'
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            // I have come i,j on cell;
            //but how to known data fill kru ya nhi.
            //only fill data empty cell
            if(board[i][j]=='.'){
                // fill this cell , col its empty
            
                // empty cell pr mujhe 1 -> 9 th digit hit and trail krne hai
                for(char digit = '1'; digit<='9';digit++){
                    // konsa digit rakh skta hu ye kaise pta kre
                    //mujhe bs check krna h k konsa digit rkhna safe hai
                    if(isSafe(digit,i,j,board)==true){
                        // if safe hai to
                        board[i][j]=digit;
                        // baki recursion sambhalega
                        bool aageSolvehopaya =  solve(board);
                        if(aageSolvehopaya == true){
                            // whole board solved
                            return true;
                        }
                        else{
                            //aage board solve nhi ho paya 
                            // Backtrack -> shayad maine galat digit rakh diya
                             board[i][j]='.';
                        }

                    }
                }
                // if you reached here
                //iska matlab ye h -> ki 1 to 9 th ka koi bhi digit yaha par fit nhi ho rha 
                // pichhe kahi galti hui hai
                return false;
            } 
        }
    } 
        // yaha aagye -> iska matlab
        //board  -> completely fill ho gya hai
        return true;
   }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        
    }
};