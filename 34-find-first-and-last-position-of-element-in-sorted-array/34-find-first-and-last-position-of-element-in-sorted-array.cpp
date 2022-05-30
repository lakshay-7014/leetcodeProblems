class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        vector<int> ans;
        int mid=s+(e-s)/2;
        //leftmost
        int left=-1;
        int right=-1;
       while(s<=e){
          if(nums[mid]==target){
              left=mid;
              e=mid-1;
          }
           else if(nums[mid]>target){
               e=mid-1;
           }
           else if(nums[mid]<target){
               s=mid+1;
           }
           mid=s+(e-s)/2;
       }
        
        s=0;
        e=nums.size()-1;
        mid=s+(e-s)/2;
        while(s<=e){
          if(nums[mid]==target){
              right=mid;
              s=mid+1;
          }
           else if(nums[mid]>target){
               e=mid-1;
           }
           else if(nums[mid]<target){
               s=mid+1;
           }
                   
           mid=s+(e-s)/2;
       }
        
        ans.push_back(left);
        ans.push_back(right);
        return ans;
    }
};
