class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ans(256,0);
        int n=s.length();
        int maxi=0;
        int left=0;
        int right=0;
        int maxi1=-1;
        while(right<n){
            if(ans[s[right]]==0){
                ans[s[right]]+=1;
                 maxi1= (right-left)+1;
                maxi=max(maxi,maxi1);
               // ans[s[right]]=1;
                right++;
            }
            else {
                ans[s[left]]-=1;
                left++;
                maxi=max(maxi,maxi1);
            }
        }
        return maxi;
        
    }
};