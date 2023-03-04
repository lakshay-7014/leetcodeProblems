//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
        // Code here
        unordered_map<int,int> mp;
        unordered_map<int,bool> mp1;
        vector<int> ans;
        int val=n/3;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            mp1[nums[i]]=true;
        }
        
        for(int i=0;i<nums.size();i++){
            if(mp1[nums[i]]==true){
                if(mp[nums[i]]>val){
                    ans.push_back(nums[i]);
                }
                mp1[nums[i]]=false;
            }
        }
        if(ans.size()==0){
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res) cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends