//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool solve(int A[],int N,int M,int val){
        int cnt=1;
        int page=0;
        for(int i=0;i<N;i++){
            if(A[i]>val){
                return false;
            }
            if(page+A[i]>val){
                cnt++;
                page=A[i];
            }
            else{
                page+=A[i];
            }
            if(cnt>M){
                return false;
            }
        }
        if(cnt>M){
            return false;
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        if(M>N){
            return -1;
        }
        int s=0;
        int e= accumulate(A,A+N,0);
        int mid=s+(e-s)/2;
        int ans=-1;
        while(s<=e){
            if(solve(A,N,M,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends