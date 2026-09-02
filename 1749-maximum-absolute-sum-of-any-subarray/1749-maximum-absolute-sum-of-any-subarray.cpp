class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minbest =nums[0];
        int maxbest = nums[0];
        int ans =abs(nums[0]);
        for(int i=1;i<nums.size();i++){
            int v1 = maxbest+nums[i];
            int v2 = minbest+nums[i];
            int v3 = nums[i];
            maxbest = max(v1,max(v2,v3));
            minbest = min(v1,min(v2,v3));
            ans = max(ans,max(maxbest,abs(minbest)));
        }
        return ans;
    }
};