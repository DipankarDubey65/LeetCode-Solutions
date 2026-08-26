class Solution {
public:
    int solve(string & s){
        int n = s.size();
        int i=0;
        long long int res =0;
        int sign =1;
        //ignore white space
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='-' || s[i]=='+')){
            sign  = (s[i]=='-'? -1:1);
            i++;
        }

        while(i<n && isdigit(s[i])){
            if(res>INT_MAX/10 || (res==INT_MAX/10 && s[i]>'7')){
                return sign == -1 ? INT_MIN : INT_MAX;

            }
            res = res*10+ (s[i] - '0');
            i++;
        }
        return res*sign;
    }
    int myAtoi(string s) {  

        return solve(s);

         //long ans =  atoi(s.c_str()); //not use this function
       // return ans;
         /*
         int i=0, num = 0,sign = 1;
         while(s[i]==' '){
            i++;
         }
         if(i<s.size() && (s[i]== '-' || s[i]=='+')){
            sign = s[i] == '+'? 1: -1;
            i++;
         }

         while(i<s.size() && isdigit(s[i])){
               if(num>INT_MAX /10 ||(num == INT_MAX/10 && s[i]> '7')){
                return sign == -1 ? INT_MIN:INT_MAX;
               }
                num = num*10 + (s[i] - '0');
                i++;
         }
         return num*sign;
         */

    }
};