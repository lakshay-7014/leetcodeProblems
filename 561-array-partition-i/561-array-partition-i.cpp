class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
           if(i%2==0){
               ans=ans+nums[i];
           } 
        }
        return ans;
    }
};