//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution
{

public:
    int xmod11(string x)
    {
       // code here
       if(x.size()==1){
           return x[0]-'0';
       }
       int i=0;
       int num=0;
       while(i<x.size()){
           num= num*10 + x[i]-'0';
           i++;
           if(num<11){
               continue;
           }
           else{
               num= num%11;
           }
       }
       return num;
       
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends