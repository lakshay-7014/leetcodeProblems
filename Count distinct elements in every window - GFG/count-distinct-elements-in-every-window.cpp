//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        //code here.
        vector<int> ans;
        unordered_map<int,int> mp;
        int cnt=0;
        
        for(int i=0;i<k;i++){
            if(mp[A[i]]==0){
                cnt++;
            }
            mp[A[i]]++;
        }
        ans.push_back(cnt);
        
        int s=0;
        for(int i=k;i<n;i++){
            mp[A[s]]--;
            if(mp[A[s]]==0){
                cnt--;
            }
            if(mp[A[i]]==0){
                cnt++;
            }
            mp[A[i]]++;
            s++;
            ans.push_back(cnt);
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

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends