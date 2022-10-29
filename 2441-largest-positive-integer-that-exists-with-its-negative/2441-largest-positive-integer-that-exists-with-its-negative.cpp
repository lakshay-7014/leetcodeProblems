class Solution {
public:
    int findMaxK(vector<int>& nums) {
        vector<int> ans(1001,0);
        int idx=-1;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int index= abs(nums[i]);
            if(ans[index]==0){
                ans[index]=nums[i];
            }
            else if(ans[index]==(nums[i] * -1) ){
                ans[index]=1001;
            }
        }
        for(int i=1000;i>=0;i--){
            if(ans[i]==1001){
                idx=i;
                break;
            }
        }
       
        return idx;
    }
};