class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size()-1;
        int i=n;
       
        while(i>=2){
            if(nums[i]==nums[i-1]+nums[i-2] || nums[i-1]+nums[i-2]==nums[i] || nums[i-1]+nums[i-2]<nums[i]){
                i--;
            }
               else{
                   int ans= nums[i]+nums[i-1]+nums[i-2];
                   return ans;
               }
        }
        return 0;
    }
};