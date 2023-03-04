//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    #define mod 1000000007
    vector<ll> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<ll>> ans;
        ans.push_back({1});
        for(int i=1;i<n;i++){
            vector<ll> temp;
            temp.push_back(1*1ll);
            for(int j=1;j<i;j++){
                //long long val= (ans[i-1][j]+ans[i-1][j-1])*1ll;
                
                long long val= ((ans[i-1][j]%mod + ans[i-1][j-1]%mod)%mod)*1ll;
                temp.push_back(val);
            }
            temp.push_back(1*1ll);
            ans.push_back(temp);
        }
        return ans[n-1];
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends