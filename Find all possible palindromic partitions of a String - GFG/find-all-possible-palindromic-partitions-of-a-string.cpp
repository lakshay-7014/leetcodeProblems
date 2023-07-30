//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   bool check(string & temp){
        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void  solve(string &str,int index,int n, vector<vector<string>> &ans,vector<string> output){
        if(index==n){
            ans.push_back(output);
            return ;
        }
        
        
        for(int i=index;i<n;i++){
            string temp=str.substr(index,i-index+1);
            if(check(temp)){
               output.push_back(temp);
               solve(str,i+1,n,ans,output);
               output.pop_back();
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string str) {
        // code here
         vector<string> output;
          vector<vector<string>> ans;
          int n = str.size();
        
          solve(str,0,n,ans,output);
          return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends