class Solution {
public:
    bool solve(vector<vector<char>>&b,string&word,int row,int col,int i){
        // aa chars matched, mil gya
        if(i==word.size()){
            return true;
        }
        if(row<0|| row>=b.size()||col<0||col>=b[0].size()|| 
        b[row][col] != word[i] || b[row][col]=='%'){   

            return false;
        }
        // I have reached here means ,current ith word char, has mathced.
        char temp = b[row][col];
        b[row][col]='%'; //visited

        bool found = solve(b,word,row+1,col,i+1) // Down
                    || solve(b,word,row-1,col,i+1) // Up
                    || solve(b,word,row,col-1,i+1) //Left
                    || solve(b,word,row,col+1,i+1); //right

        //unvisited
        b[row][col]= temp;
        return found;


    }

    bool solved(vector<vector<char>>& board, string word,int r,int c,int i){
        //base case
        if(i==word.size()){
            return true;
        }
        if(r<0||r>=board.size()|| c<0||c>=board[0].size()||board[r][c] != word[i] 
        || board[r][c] == '%'){
            return false;
        }
        char temp = board[r][c];
        board[r][c] = '%'; //visited

        bool found = solve(board,word,r+1,c,i+1) // down
        || solve(board,word,r-1,c,i+1) // up
        || solve(board,word,r,c-1,i+1) // left
        || solve(board,word,r,c+1,i+1) ;// right

        board[r][c] = temp;

        return found;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solved(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
        
    }
};