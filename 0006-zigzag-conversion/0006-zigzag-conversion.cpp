class Solution {
public:
    string solve(string&s, int&numRows){

        if(numRows == 1|| numRows > s.size()){
            return s;
        }
        int currow  =0;
        bool uptodown  = false;
        vector<string>rows (min(numRows,int(s.size())));
        for(char c: s){
            rows[currow] += c;
            if(currow  == 0 || currow == numRows-1){

                uptodown = !uptodown;
            } 
            currow  += uptodown? 1 : -1;

        }
           string res;
        for(string r: rows){
            res += r;

        }
        return res;

     }
    string convert(string s, int numRows) {
       
       return solve(s,numRows);
    }
};