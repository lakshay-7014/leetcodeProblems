//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define mod 1000000007
    int solve(int target,int A[],int n,int k){
        int ans=0;
        for(int i=0;i<n;i++){
            int elem= abs(A[i]-target);
            if(elem%k !=0){
                return -1;
            }
            else{
                int val= elem/k;
                ans=(ans%mod + val%mod)%mod;
            }
        }
        return ans;
    }
    int equalizeArray(int N, int k, int A[]){
        // code here
        sort(A,A+N);
        if(N%2!=0){
            int mid=N/2;
            int op= solve(A[mid],A,N,k);
            return op;
        }
        else{
            int mid1=N-1 / 2;
            int mid2=N/2;
            int op1=solve(A[mid1],A,N,k);
            int op2=solve(A[mid2],A,N,k);
            if(op1!=-1 && op2!=-1){
                return min(op1,op2);
            }
            else if(op1!=-1 && op2==-1){
                return op1;
            }
            else if(op1==-1 && op2!=-1){
                return op2;
            }
            else{
                return -1;
            }
        }
        return-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, k;
        cin>>N>>k;
        int A[N];
        for(int i = 0; i < N; i++)
            cin>>A[i];
            
        Solution ob;
        cout<<ob.equalizeArray(N, k, A)<<"\n";
    }
    return 0;
}
// } Driver Code Ends