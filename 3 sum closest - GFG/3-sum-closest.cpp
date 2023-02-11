//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
        sort(A,A+N);
        int target=X;
        
        int diff=INT_MAX;
        int maxiSum=INT_MIN;
        for(int i=0;i<N;i++){
            int st=i+1;
            int en=N-1;
            
            while(st<en){
                int sum= A[i]+A[st]+A[en];
                
                int val=abs(target-sum);
                if(val<diff){
                    diff=val;
                    maxiSum=sum;
                }
                if(val==diff){
                    maxiSum=max(maxiSum,sum);
                    st++;
                }
                if(sum<target){
                    st++;
                }
                else if(sum>target){
                    en--;
                }
            }
        }
        return maxiSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends