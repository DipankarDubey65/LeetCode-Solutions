class Solution {
public:
    void solve(string &output,unordered_map<char,string>&mapping, vector<string>&ans,string digits,int i){
        //base case
        if(i>=digits.size()){
            if(output.size()>0){
                ans.push_back(output);
            }
            return ;
        }
        //1 case i will solve and onother case recursion solve
        char digi = digits[i];
        string mappedString = mapping[digi];

        for(char ch: mappedString){
            //hr character k liye crecursive call marni hai ,after including in output string
            output.push_back(ch);
            // recursive call
            solve(output,mapping,ans,digits,i+1);
            //backtrack
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        unordered_map<char,string>mapping;

        mapping['2']="abc";
        mapping['3']="def";
        mapping['4']="ghi";
        mapping['5']="jkl";
        mapping['6']="mno";
        mapping['7']="pqrs";
        mapping['8']="tuv";
        mapping['9']="wxyz";
      
       string output="";
        int i=0;
        solve(output,mapping,ans,digits,i);

        return ans;


    }
};