class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int s1 = nums[0];
        int bestend =nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = bestend+nums[i];
            int v2 = nums[i];
            bestend = max(v1,v2);
            s1 = max(s1,bestend);
        }
        if(s1<0){
            return s1;
        }
        int totalsum = nums[0];
        int smin =nums[0];
        int bestmin = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = bestmin+nums[i];
            int v2 = nums[i];
            bestmin = min(v1,v2);
            smin = min(smin,bestmin);
            totalsum +=nums[i];
        }
        int s2 = (totalsum-smin);
        cout<<totalsum<<endl;
        cout<<smin<<endl;

        return max(s1,s2);
    }
};