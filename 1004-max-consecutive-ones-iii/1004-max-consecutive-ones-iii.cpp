class Solution {
public:

    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int res =-1;
        vector<int>f(2,0);
        for(int h=0;h<nums.size();h++){
            f[nums[h]]++;
            int len = h-l+1;
            
            
            while(f[0]>k){
                f[nums[l]]--;
                l++;
                
            }
            len = h-l+1;
            res = max(res, len);
        }
        return res;
    }
};