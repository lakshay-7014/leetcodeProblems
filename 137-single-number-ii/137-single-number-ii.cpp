class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ones=0;
        int twos=0;
        for(int i=0;i<n;i++){
            ones=ones^nums[i];
            ones=ones& ~(twos);
            
            twos=twos^nums[i];
            twos=twos& ~(ones);
        }
        return ones;
    }
};