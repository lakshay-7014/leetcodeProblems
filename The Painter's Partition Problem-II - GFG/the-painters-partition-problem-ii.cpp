//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
  
     bool solve(int A[],int N,int M,long long val){
        int cnt=1;
        long long tim=0;
        for(int i=0;i<N;i++){
            if(A[i]>val){
                return false;
            }
            if(tim+A[i]>val){
                cnt++;
                tim=A[i];
            }
            else{
                tim+=A[i];
            }
            if(cnt>M){
                return false;
            }
        }
        return true;
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        long long s=0;
        long long e=0;
        for(int i=0;i<n;i++){
            e+=arr[i];
        }
        long long mid=s+(e-s)/2;
        long long ans=-1;
        while(s<=e){
            if(solve(arr,n,k,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends