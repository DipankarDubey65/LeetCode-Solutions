class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=1;
        int k=1;
        int count=1;
        if(nums.size()==1){
            return 1;
        }
        while(i<j && j<nums.size()){
            if(nums[j-1]==nums[j]){
                j++;
            }
            else if(nums[j-1] != nums[j]){
                nums[i+1]=nums[j];
                count++;
                i++;
                j++;
            }
        }
        return count;
    }
};