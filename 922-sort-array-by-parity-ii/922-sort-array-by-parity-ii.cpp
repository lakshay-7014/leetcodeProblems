class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        int a=0;
        int b=1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[a]=nums[i];
                a=a+2;
            }
            else{
                ans[b]=nums[i];
                b=b+2;
            }
        }
        return ans;
    }
};