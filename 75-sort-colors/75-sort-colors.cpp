class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        int mid=0;
        int e=n-1;
        while(mid<=e){
            if(nums[mid]==0){
                swap(nums[mid],nums[s]);
                s++;
                mid++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[e]);
                e--;
                
            }
            else{
                mid++;
            }
        }
        
    }
};