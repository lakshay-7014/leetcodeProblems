//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int i=0;
        int j=0;
        int zero=0;
        int ans=0;
        int cnt=0;
        while(j<n){
            if(arr[j]==1){
                
            }
            else if(arr[j]==0 && zero<m){
              
              zero++;
            }
            else{
                ans=max(ans,j-i);
                while(arr[i]!=0){
                    i++;
                }
                i++;
                
            }
            j++;
        }
       ans=max(ans,j-i);
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends