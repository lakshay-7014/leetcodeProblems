class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> count(101,0);
        for(int i=0;i<n;i++){
            count[nums[i]]+=1;
        }
        
        for(int i=0;i<n;i++){
            if(count[nums[i]]>1){
                int value=count[nums[i]];
                value= ((value) * (value-1))/2;
                ans+=value;
                count[nums[i]]=0;
            }
        }
        
        return ans;
    }
};