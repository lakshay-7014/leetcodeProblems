//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(int i,vector<int>&A ,int target){
        if(i>=A.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }
        int inc= solve(i+1,A,target-A[i]);
        int exc= solve(i+1,A,target+A[i]);
        return inc+exc;
    }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        return solve(0,A,target);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends