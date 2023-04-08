//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    bool solve(string &s){
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    int addMinChar(string str){
        
        int ans=0;
        
        int i=0;
        int j= str.length()-1;
        
        while(i<j){
            if(solve(str)){
                break;
            }
            else{
                ans++;
                str= str.substr(0,j-i);
                j=str.size()-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends