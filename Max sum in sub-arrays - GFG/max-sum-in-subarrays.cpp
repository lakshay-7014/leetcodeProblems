//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long maxi=arr[0]+arr[1];
        long long curr =arr[0]+arr[1];
        int s=0;
        for(long long i=2;i<N;i++){
            curr=curr-arr[s];
            curr+=arr[i];
            if(curr>maxi){
                maxi=curr;
            }
            s++;
        }
        return maxi;
        
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends