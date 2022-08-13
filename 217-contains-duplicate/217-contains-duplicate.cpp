class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        long long n= nums.size();
        unordered_map<int,int > ans;
        for(int i=0;i<n;i++){
            ans[nums[i]]+=1;
            if( ans[nums[i]]==2){
                return true;
            }
        }
        return 0;
    }
};