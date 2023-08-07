//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    #define mod 1000000007
    int permutationCoeff(int n, int k){
        //Code here
        long long int prod=1;
        for(int i=n;i>(n-k);i--){
            prod=((prod%mod)*(i%mod))%mod;
        }
        return prod%mod;
    }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Solution ob;
        int ans = ob.permutationCoeff(n,k);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends