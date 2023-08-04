//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void solve2(stack<int>&s,int elem){
        if(s.size()==0){
            s.push(elem);
            return ;
        }
        int val= s.top();
        s.pop();
        solve2(s,elem);
        s.push(val);
    }
    void solve(stack<int> &s){
        if(s.size()==0){
            return;
        }
        int elem=s.top();
        s.pop();
        solve(s);
        
        solve2(s,elem);
        
    }
    void Reverse(stack<int> &St){
        solve(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends