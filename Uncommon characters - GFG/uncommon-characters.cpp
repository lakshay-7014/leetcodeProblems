//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        string UncommonChars(string A, string B)
        {
            // code here
            map<char,int> mp1;
            map<char,int> mp2;
            int n1= A.length();
            int n2= B.length();
            
            for(int i=0;i<n1;i++){
                mp1[A[i]]=1;
            }
            
            for(int i=0;i<n2;i++){
                if(mp1.find(B[i])!=mp1.end()){
                    mp1[B[i]]=0;
                }
                else{
                    mp2[B[i]]=1;
                }
            }
            string res="";
            for(int i=0;i<n1;i++){
               if(mp1[A[i]]==1){
                   res+=A[i];
                   mp1[A[i]]=0;
               }
            }
            for(int i=0;i<n2;i++){
                if(mp2.find(B[i]) !=mp2.end()){
                    if(mp2[B[i]]==1){
                         res+=B[i];
                        mp2[B[i]]=0;
                    }
                   
                
                }
            }
            if(res.length()==0){
                return "-1";
            }
            sort(res.begin(),res.end());
            return res;
            
        }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        Solution ob;
        cout<<ob.UncommonChars(A, B);
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends