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

//Bit Manipulation 
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
