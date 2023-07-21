//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s1)
{
    // your code here
    stack<char> s;
    int n = s1.size();
    for(int i=0;i<n;i++){
        if(s1[i]=='{'){
            s.push(s1[i]);
        }
        else{
            if(s.size()!=0){
                if(s.top()=='{'){
                    s.pop();
                }
                else{
                    s.push(s1[i]);
                }
            }
            else{
                s.push(s1[i]);
            }
        }
    }
    int ans=0;
    while(s.size()!=0){
        char c= s.top();
        s.pop();
        if(s.size()==0){
            return -1;
        }
        char o=s.top();
        s.pop();
        if(c=='{'){
            ans++;
        }
        if(o=='}'){
            ans++;
        }
    }
    return ans;
    
}