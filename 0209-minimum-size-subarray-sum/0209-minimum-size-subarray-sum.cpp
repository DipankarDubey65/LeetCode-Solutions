class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int ans = INT_MAX;
       int sum=0;
       int l=0;
       for(int h=0;h<nums.size();h++){
        sum += nums[h];
        while(sum>=target){
            int len = h-l+1;
            ans = min(ans,len);
            sum -= nums[l];
            l++;
        }
       } 
       return ans==INT_MAX? 0:ans;
    }
};