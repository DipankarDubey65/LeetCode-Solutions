class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            int Lsum=0;
            int Rsum=0;
            for(int j=0;j<i;j++){
                Lsum +=nums[j];
            }
            for(int j=i+1;j<n;j++){
                Rsum +=nums[j]; 
            }
            if(Lsum==Rsum){
                return i;
            }
        }
        return -1;
    }
};