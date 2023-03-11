//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	    int s=1;
	    int e=m;
	    int mid=s+(e-s)/2;
	    while(s<=e){
	        int p=pow(mid,n);
	        //cout<<p<<" ";
	        if(p==m){
	            return mid;
	        }
	        else if(p==INT_MIN || p==INT_MAX){
	            e=mid-1;
	        }
	        else if(p>m){
	            e=mid-1;
	        }
	        else {
	            s=mid+1;
	        }
	        mid=s+(e-s)/2;
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends