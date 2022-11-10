//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  static const int mod=1e8;
  int rec(vector<int> &arr,int n){
      if(n<2){
          return 1;
      }
      if(arr[n]!=-1){
          return arr[n];
      }
      int ans=0;
      ans=(rec(arr,n-1) % mod+rec(arr,n-2)%mod)%mod;
      arr[n]=ans;
      return ans;
  }
    int fillingBucket(int N) {
        // code here
        vector<int> arr(100001,-1);
       return rec(arr,N);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.fillingBucket(N) << endl;
    }
    return 0;
}
// } Driver Code Ends