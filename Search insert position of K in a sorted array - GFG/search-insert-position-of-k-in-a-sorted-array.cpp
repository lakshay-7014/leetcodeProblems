//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
        // code here
        int s=0;
        int e=N-1;
        int mid=s+(e-s)/2;
        while(s<e){
            int elem=Arr[mid];
            if(elem==k){
                return mid;
            }
            else if(elem>k){
                e=mid;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        if(k>Arr[N-1]){
            return N;
        }
        return s;
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
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends