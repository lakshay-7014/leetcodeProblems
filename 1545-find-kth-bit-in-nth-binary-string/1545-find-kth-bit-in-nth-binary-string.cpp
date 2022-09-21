class Solution {
public:
    void solve(string &ans ,int s,int n, int k){
        if(s>=n-1){
            //cout<<ans<<"er";
            return ;
        }
        string rev="";
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]=='1'){
                rev+='0';
            }
            else{
                rev+='1';
            }
            
        }
        ans=ans+'1'+rev;
        s++;
        solve(ans,s,n,k);
        
    }
    char findKthBit(int n, int k) {
        string ans="0";
        int s=0;
        solve(ans,s,n,k);
       // cout<<ans<<" er";
        char c=ans[k-1];
        return c;
        
    }
};