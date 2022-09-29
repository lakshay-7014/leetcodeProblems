class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int ,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
               mp[nums[i]]=i; 
            }
        }
        
        for(int i=1;i<=n+1;i++){
            if(mp.find(i)==mp.end()){
                return i;
            }
        }
        return -1;
    }
};