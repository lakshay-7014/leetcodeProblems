//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void solve(string &ans,int n ,string &str,int k,int index){
       if(ans<str){
           ans=str;
       }
        if(k==0){
            return ;
        }
        if(index==n){
            return ;
        }
        
        for(int i=index+1;i<n;i++){
            if(str[i]>str[index]){
                swap(str[i],str[index]);
                solve(ans,n,str,k-1,index+1);
                swap(str[i],str[index]);
            }
        }
        solve(ans,n,str,k,index+1);
        
    }
    string findMaximumNum(string str, int k)
    {
       // code here.
       int n = str.size();
       string ans="";
       
       solve(ans,n,str,k,0);
       return ans;
       
       
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends