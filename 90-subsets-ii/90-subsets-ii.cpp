class Solution {
    private:
    void solve(vector<int> nums,vector<int> output,int index, vector<vector<int>> &ans){
        if(index>=nums.size()){
            int s= ans.size();
            int flag=true;
            for(int i=0;i<s;i++){
                if(ans[i]==output){
                    flag=false;
                    break;
                }
            }
            if(flag==true){
                ans.push_back(output);
            }
            
            return ;
        }
        //exclude krna hai
        solve(nums,output,index+1,ans);
        
        //include krna hai
        output.push_back(nums[index]);
        solve(nums,output,index+1,ans);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(),nums.end());
        int index=0;
        solve(nums,output,index,ans);
        
        return ans;
    }
};