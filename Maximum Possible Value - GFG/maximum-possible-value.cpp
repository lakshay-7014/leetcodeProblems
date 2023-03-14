//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int N,vector<int> A, vector<int> B) {
        // code here
        long long ans=0;
        int stick=0;
        int mini=INT_MAX;
        for(int i=0;i<N;i++){
            if(B[i]%2!=0){
                B[i]--;
            }
            if(B[i]==0){
                continue;
            }
            mini=min(mini,A[i]);
            stick+=B[i];
            ans+=1ll*A[i]*B[i];
        }
        if(stick%4!=0){
            ans-=1ll*2*mini;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends