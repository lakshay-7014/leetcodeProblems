//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<R;i++){
            maxi=max(maxi,matrix[i][C-1]);
            mini=min(mini,matrix[i][0]);
        }
        
        int mid = (R*C + 1)/2;
        
        while(mini<maxi){
            int mid1=mini+(maxi-mini)/2;
            int cnt=0;
            for(int i=0;i<R;i++){
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid1)-matrix[i].begin();
            }
            if(cnt<mid){
                mini=mid1+1;
            }
            else{
                maxi=mid1;
            }
        }
        return mini;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends