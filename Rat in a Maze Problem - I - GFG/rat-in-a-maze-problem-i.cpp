//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool check(int x,int y,vector<vector<bool>> &vis,vector<vector<int>> &m){
        if(x>=0 &&x<m.size() && y>=0 && y<m.size() && vis[x][y]==0 && m[x][y]==1){
            return true;
        } 
        return false;
    }
    void solve(vector<string> &ans,string path,vector<vector<int>> &m,int x,int y, vector<vector<bool>> &vis){
        if(x==m.size()-1 && y==m.size()-1){
            ans.push_back(path);
            return ;
        }
        vis[x][y]=1;
        //down
        int newx=x+1;
        int newy=y;
        if(check(newx,newy,vis,m)){
            path+='D';
            solve(ans,path,m,newx,newy,vis);
            path.pop_back();
        }
        //up
        newx=x-1;
        newy=y;
         if(check(newx,newy,vis,m)){
            path+='U';
            solve(ans,path,m,newx,newy,vis);
            path.pop_back();
        }
        
        //LEFT
        newx=x;
        newy=y-1;
         if(check(newx,newy,vis,m)){
            path+='L';
            solve(ans,path,m,newx,newy,vis);
            path.pop_back();
        }
        
        //right
        newx=x;
        newy=y+1;
         if(check(newx,newy,vis,m)){
            path+='R';
            solve(ans,path,m,newx,newy,vis);
            path.pop_back();
        }
        vis[x][y]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0){
            return {};
        }
        vector<string> ans;
        string path="";
        vector<vector<bool>> vis(n,vector<bool>(n,0));
        
        solve(ans,path,m,0,0,vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends