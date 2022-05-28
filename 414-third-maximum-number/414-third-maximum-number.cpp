class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int max=nums[n-1];
        int count=1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<max && count<=3){
                count++;
                max=nums[i];
                if(count==3){
                    
                    return max;
                }    
            }
        }   
        return nums[n-1];
    }
};