class Solution {
    private:
     int getpivot(vector<int>& arr){
         int s=0;
         int e=arr.size()-1;
         int mid=s+(e-s)/2;
         while(s<e){
             if(arr[0]<=arr[mid]){
                 s=mid+1;
             }
             else{
                 e=mid;
             }
             mid=s+(e-s)/2;
         }
         return mid;
     }
    int binarysearch(vector<int>& nums,int s,int e,int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    
public:
    
    int search(vector<int>& nums, int target) {
        int pivot= getpivot(nums);
        int n=nums.size()-1;
        if(target>=nums[pivot] && target<=nums[n]){
            return binarysearch(nums,pivot,n,target);
        }
        else{
            return binarysearch(nums,0,pivot-1,target);
        }
        return 0;
    }
};