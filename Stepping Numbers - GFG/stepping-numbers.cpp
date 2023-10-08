//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int cnt=0;
    void solve(int n,int m , int num){
        if(num>m){
            return ;
        }
        if(num>=n && num<=m){
            cnt++;
        }
        int dig=num%10;
            if(dig!=0){
                int prev=num*10+(dig-1);
              ///  cnt++;
                solve(n,m,prev);
            }
            if(dig!=9){
                int nex=num*10+(dig+1);
                //cnt++;
                solve(n,m,nex);
        }
    }
    int steppingNumbers(int n, int m)
    {
        // Code Here
        if(n==0){
            cnt++;
        }
        for(int i=1;i<=9;i++){
            solve(n,m,i);
        }
        return cnt;
        
    }
};


//{ Driver Code Starts.

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        Solution obj;
        int n, m;
        cin>>n>>m;
        cout << obj.steppingNumbers(n,m) << endl;
    }
	return 0;
}


// } Driver Code Ends