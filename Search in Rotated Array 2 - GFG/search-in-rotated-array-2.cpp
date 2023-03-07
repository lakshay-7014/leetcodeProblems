//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int pivot(vector<int> &arr,int s , int e){
        int mid=s+(e-s)/2;
        
        int ans=-1;
        while(s<e){
           
             if(arr[0]<=arr[mid]){
                s=mid+1;
            }
             else {
                e=mid;
            }
            mid=s+(e-s)/2;
        }
        return s;
    }
    int binary(vector<int>& arr,int s , int e , int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==target || arr[s]==target || arr[e]==target){
                return 1;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return 0;
    }
    bool Search(int N, vector<int>& A, int Key) {
        // Code here
        int p = pivot(A,0,N);
       // cout<<p<<"jj";
        if(p!=N && Key>=A[p] && Key<=A[N-1]){
            return binary(A,p,N-1,Key);
        }
        else {
            return binary(A,0,p-1,Key);
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends