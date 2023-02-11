//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    // Your code goes here
	   sort(arr,arr+n);
	   long long ans=0;
	   for(int i=0;i<n;i++){
	       //cout<<arr[i]<<" ";
	   }
	    for(int i=0;i<n;i++){
	        int st=i+1;
	        int en=n-1;
	        
	        while(st<en){
	            long long sum1=arr[i]+arr[st]+arr[en];
	            if(sum1>=sum){
	                en--;
	            }
	            else if(sum1<sum){
	                ans+=en-st;
	                st++;
	            }
	        }
	    }
	    return ans;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends