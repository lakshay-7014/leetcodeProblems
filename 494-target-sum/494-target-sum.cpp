class Solution {
    private:
    void solve(vector<int>& nums,int target, int idx,int sum , int &count){
        if(idx>=nums.size()){
            if(sum==target){
                count++;
            }
            return ;
        }
        
        solve(nums,target,idx+1,sum+nums[idx],count);
        solve(nums,target,idx+1,sum-nums[idx],count);
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int count=0;
        int idx=0;
        solve(nums,target,idx,sum,count);
        return count;
    }
};