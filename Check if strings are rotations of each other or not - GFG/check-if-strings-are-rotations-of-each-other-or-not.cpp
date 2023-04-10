//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1==s2){
            return true;
        }
        if((int)s1.size()!=(int)s2.size()){
            return false;
        }
        int i=0;
        while(i<s2.size()){
            char c = s2.back();
            s2.pop_back();
            s2=c+s2;
            if(s1==s2){
                return true;
            }
            i++;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends