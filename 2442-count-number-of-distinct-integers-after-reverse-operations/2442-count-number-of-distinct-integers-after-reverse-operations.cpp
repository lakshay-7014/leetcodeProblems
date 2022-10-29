class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int rev=0;
            int num=nums[i];
            while(num!=0){
                int lastdig=num%10;
                rev=rev*10+lastdig;
                num=num/10;
            }
            nums.push_back(rev);
        }
        set<int> ans;
        n=nums.size();
        for(int i=0;i<n;i++){
            ans.insert(nums[i]);
        }
        return ans.size();
    }
};