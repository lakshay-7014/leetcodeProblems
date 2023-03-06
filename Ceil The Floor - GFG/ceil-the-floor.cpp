//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    pair<int,int> p;
    sort(arr,arr+n);
    if(x<arr[0]){
        p.first=-1;
    }
    for(int i=0;i<n;i++){
        if(arr[i]<=x){
            p.first=arr[i];
        }
        else{
            break;
        }
    }
    
    if(x>arr[n-1]){
        p.second=-1;
    }
    
   for(int i=0;i<n;i++){
       if(arr[i]==x){
           p.second=arr[i];
           break;
       }
       else if(arr[i]>x){
           p.second=arr[i];
           break;
       }
   }
    return p;
}