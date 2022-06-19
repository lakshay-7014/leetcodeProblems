class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n=num.size()-1;
        int r=0;
        int flag=0;
        vector<int> ans;
        while(n>=0){
            int lastdig=k%10;
            int ans1 =num[n]+lastdig+r;
            ans.insert(ans.begin(),ans1%10);
            r=ans1/10;
            n--;
            k=k/10;
        }
        while(k!=0){
            int lastdig=k%10;
            int ans1=lastdig+r;
            ans.insert(ans.begin(),ans1%10); 
            r=ans1/10;
            k=k/10;
        }
        if(r!=0){
        ans.insert(ans.begin(),r);
        }
        return ans;
    }
};