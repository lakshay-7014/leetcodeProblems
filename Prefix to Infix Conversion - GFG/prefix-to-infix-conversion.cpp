//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre) {
        // Write your code here
        stack<string> s;
        for(int i=pre.size()-1;i>=0;i--){
            string temp="";
            char c= pre[i];
            if((c>='A' && c<='Z') || (c>='a' && c<='z')){
                temp+=c;
                s.push(temp);
            }
            else{
                string s1= s.top();
                s.pop();
                string s2=s.top();
                s.pop();
                s1='('+s1+c+s2+')';
                s.push(s1);
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends