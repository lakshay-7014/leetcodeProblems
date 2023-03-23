//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){
            int f1= s.top();
            s.pop();
            int f2=s.top();
            s.pop();
            
            if(M[f1][f2]==1){
                s.push(f2);
            }
            else if(M[f2][f1]==1){
                s.push(f1);
            }
        }
        if(s.size()==0){
            return -1;
        }
        int elem=s.top();
        //cout<<elem<<"jj";
        for(int i=0;i<n;i++){
            if(M[elem][i]==1){
                return -1;
            }
        }
        for(int i=0;i<n;i++){
            if( elem!=i && M[i][elem]==0){
                return -1;
            }
        }
        return elem;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends