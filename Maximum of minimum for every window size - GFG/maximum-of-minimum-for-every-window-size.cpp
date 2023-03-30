//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int> next(n);
        vector<int> prev(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--){
            while(s.size()!=0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                next[i]=n;
            }
            else{
                next[i]=s.top();
            }
            s.push(i);
        }
        while(s.size()!=0){
            s.pop();
        }
        for(int i=0;i<n;i++){
            while(s.size()!=0 && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.size()==0){
                prev[i]=-1;
            }
            else{
                prev[i]=s.top();
            }
            s.push(i);
        }
        
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            int val= next[i]-prev[i]-1;
            if(val==n){
                res[n-1]=max(res[n-1],arr[i]);
            }
            else{
                res[val-1]= max(res[val-1],arr[i]);
            }
            
        }
        int val= res[n-1];
        for(int i=n-1;i>=0;i--){
            if(res[i]==0){
                res[i]=val;
            }
            else if(res[i]<val){
                res[i]=val;
            }
            else{
                val=res[i];
            }
        }
        
        return res;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends