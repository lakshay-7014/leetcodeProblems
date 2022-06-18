class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[s]){ //left arrray sorted hai
               if(target >=nums[s] && target <=nums[mid]){
                   e=mid;
               }
                else{
                    s=mid+1;
                }
                
            }
            else if(nums[mid]<=nums[s]){
                if(target>=nums[mid] && target<=nums[e]){
                    s=mid+1;
                }
                else{
                    e=mid;
                }
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
};