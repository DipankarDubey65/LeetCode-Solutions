class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum =0;
        int left = 0;
        int right = 0;
        for(auto i:nums){
            sum+=i;
        }
        for(int i=0;i<nums.size();i++){
            
            right = sum-nums[i]-left;
            if(left==right){
                return i;
            }
            left +=nums[i];
            
        }
        return -1;

    }
};