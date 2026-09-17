class Solution {
public:
    int findMaxLength(vector<int>& nums){
        int zero=0;
        int one=0;
        unordered_map<int,int>mp;
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero++;
            }else{
                one++;
            }
            int diff = zero-one;
            if(diff==0){
                res = max(res,i+1);
                continue;
               
            }
            if(mp.find(diff)!=mp.end()){
                 int idx = mp[diff];
                 int len = i-idx;
                res = max(res,len);
            }
            else{
                mp[diff] = i;
               
            }
            
        }
        return res;

    } 
    
};