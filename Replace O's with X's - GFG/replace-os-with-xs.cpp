//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int i , int j , int n , int m ,vector<vector<char>> &mat){
        if(mat[i][j]=='O'){
            mat[i][j]='P';
            if(i-1>=0){
                dfs(i-1,j,n,m,mat);
            }
            if(j-1>=0){
                dfs(i,j-1,n,m,mat);
            }
            if(i+1<n){
                dfs(i+1,j,n,m,mat);
            }
            if(j+1<m){
                dfs(i,j+1,n,m,mat);
            }
        }
        
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0  || i==n-1 || j==m-1){
                    dfs(i,j,n,m,mat);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='P'){
                    mat[i][j]='O';
                }
                else{
                    mat[i][j]='X';
                }
            }
        }
        return mat;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends