//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string s1, string s2) {
        // Write your Code here
        int i=0;
        int j=0;
        int k=0;
        string ans="";
        if(s2.size()>s1.size()){
            return ans;
        }
        while(j<s1.size()){
            if(s1[j]==s2[k]){
                j++;
                k++;
                
                if(k==s2.size()){
                    i=j;
                    k=k-1;
                    while(k>=0){
                        if(s1[i]==s2[k]){
                            i--;
                            k--;
                        }
                        else{
                            i--;
                        }
                    }
                    string temp=s1.substr(i+1,j-i-1);
                    int sz=temp.size();
                    
                    if(ans.size()==0){
                        ans=temp;
                    }
                    else if(ans.size()>sz){
                        ans=temp;
                    }
                    k=0;
                }
            }
            else if(s1[j]!=s2[k]){
                j++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends