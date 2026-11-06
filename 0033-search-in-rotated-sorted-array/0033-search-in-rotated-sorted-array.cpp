class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s =0;
        int e = n-1;
        int edge = -1;
      // Edge point find
        while(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]>nums[n-1]){
                s = mid+1;
            }
            else{
                edge = mid;
                e = mid-1;
            }
        }

        int s1 = 0;
        int e1 = edge-1;
        while(s1<=e1){
            int mid =s1+(e1-s1)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                e1 = mid-1;
            }
            else{
                s1 = mid+1;
            }
        }
      
         int s2 = edge;
         int e2 = n-1;
         while(s2<=e2){
            int mid = s2+(e2-s2)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                e2 = mid-1;
            }
            else{
              s2 =  mid+1;
            }
         }

         return -1;
    }
};