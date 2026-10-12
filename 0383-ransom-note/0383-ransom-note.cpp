class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n =ransomNote.size();
        int m = magazine.size();
        unordered_map<char,int>need;
        unordered_map<char,int>have;
        for(int i=0;i<n;i++){
            need[ransomNote[i]]++;
        }
        for(int i=0;i<m;i++){
            have[magazine[i]]++;
        }
        for(auto i:need){
            if(need[i.first]>have[i.first]){
                return false;
            }  
        }
        return true;
    }
};