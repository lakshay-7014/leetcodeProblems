//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int s=0;
	    int e=n-1;
	    int idx1=-1;
	    int mid=s+(e-s)/2;
	    while(s<=e){
	        int elem = arr[mid];
	        if(elem==x){
	            idx1=mid;
	            e=mid-1;
	        }
	        else if(elem>x){
	            e=mid-1;
	        }
	        else{
	            s=mid+1;
	        }
	        mid=s+(e-s)/2;
	    }
	    
	    s=0;
	    e=n-1;
	    int idx2=-1;
	     while(s<=e){
	        int elem = arr[mid];
	        if(elem==x){
	            idx2=mid;
	            s=mid+1;
	        }
	        else if(elem>x){
	            e=mid-1;
	        }
	        else{
	            s=mid+1;
	        }
	        mid=s+(e-s)/2;
	    }
	    
	    if(idx1==-1){
	        return 0;
	    }
	    return idx2-idx1+1;
	    
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends