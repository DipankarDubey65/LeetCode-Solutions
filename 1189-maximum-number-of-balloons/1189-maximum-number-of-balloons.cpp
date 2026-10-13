class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>have;
        unordered_map<char,int>need;
        int res = INT_MAX;
        int n =text.size();
        for(int i=0;i<n;i++){
            have[text[i]]++;
        }
        string text2 = "balloon";
        for(auto i :text2){
            need[i]++;
        }
        for(auto i:need){
            char c = i.first;
            int times = have[c]/need[c];
            res = min(res,times);
        }
        return res;

    }
};