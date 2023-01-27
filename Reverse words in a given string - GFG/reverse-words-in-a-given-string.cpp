//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        string ans="";
        for(int i=S.length()-1;i>=0;i--){
            int j=i;
            string temp="";
            while(j>=0 && S[j]!='.'){
                temp=S[j]+temp;
                j--;
            }
            i=j;
            ans+=temp+".";
            
        }
        int sz= ans.size()-1;
        ans.erase(ans.begin()+sz);
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends