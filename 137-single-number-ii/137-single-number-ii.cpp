class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        while(i<n){
            if(i<n-2 && nums[i]==nums[i+1] && nums[i+1]==nums[i+2]){
                i=i+2;
            }
            else{
                return nums[i];
            }
            i++;
        }
        return -1;
    }
};