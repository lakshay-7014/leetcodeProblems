//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        vector<int> next(n);
        vector<int> prev(n);
        int val=0;
        
        long long ans=0;
        for(int i=n-1;i>=0 ;i--){
            next[i]=val;
            val=max(val,arr[i]);
        }
        
        val=0;
        for(int i=0;i<n;i++){
            prev[i]=val;
            val=max(val,arr[i]);
        }
        
        for(int i=0;i<n;i++){
            int val= min(prev[i],next[i])- arr[i];
            if(val>=0){
                ans+=val;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends