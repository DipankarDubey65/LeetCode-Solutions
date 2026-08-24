class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char,int>mp;
        int l=0;
        
       
        for(int h=0;h<s.size();h++){
            mp[s[h]]++;
            int k = h-l+1;
            while(mp.size()<k){
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);           
                }
                l++;
                 k=h-l+1;

            }
            int len = h-l+1;
            res = max(res,len);  


         
        }
        return res;
    }
};