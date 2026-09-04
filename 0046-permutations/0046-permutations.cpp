class Solution {
public:
   void solve(vector<int>& nums,int i,vector<vector<int>>&ans){
      //Base case
      if(i>=nums.size()){
        ans.push_back(nums);
        return;
      }

      for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(nums,i+1,ans);
        //back tracking
        swap(nums[i],nums[j]);
        
      }

   }
 
 void solved(vector<int>nums,int i,vector<vector<int>>&ans){
    // base case
    if(i>=nums.size()){
        ans.push_back(nums);
        return;
    }

    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);

        solved(nums,i+1,ans);
        


    }

 }

 //short method for permutation
void easy(vector<int>nums,vector<vector<int>>&ans){
    sort(nums.begin(),nums.end());
    ans.push_back(nums);
    while(next_permutation(nums.begin(),nums.end())){
        ans.push_back(nums);
    }
 }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int i =0;
        //solve(nums,i,ans);
       // solved(nums,i,ans);
        
        easy(nums,ans);
        return ans;

        
    }
};