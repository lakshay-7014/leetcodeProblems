class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
        vector<int> ans;
        int r=1;
       while(n>=0){
           int ans1=digits[n]+r;
           int lastdig=ans1%10;
           ans.insert(ans.begin(),lastdig);
           r=ans1/10;
           n--;
       }
        if(r!=0){
        ans.insert(ans.begin(),r);     
        }
       
        return ans;
    }
};