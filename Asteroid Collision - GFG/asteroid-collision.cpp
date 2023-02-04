//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &ast) {
        // code here
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<N;i++){
            if(ast[i]==0){
                continue;
            }
            // 0 waala case
            if(s.empty()){
                s.push(ast[i]);
            }
            else{
                int top=s.top();
                if((top>0 && ast[i]>0) || (top<0 && ast[i]<0)){
                    s.push(ast[i]);
                }
                else{
                    if(abs(top) == abs(ast[i])){
                        if(top>0 && ast[i]<0){
                            s.pop();
                        }
                        else{
                            s.push(ast[i]);
                        }
                    }
                    else if(abs(top) > abs(ast[i])){
                        if(top<0 && ast[i]>0){
                             s.push(ast[i]);
                        }
                    }
                    else if(abs(top) < abs(ast[i])){
                        if(top>0 && ast[i]<0){
                            s.pop();
                            i--;
                        }
                        else{
                            s.push(ast[i]);
                        }
                    }
                }
            }
        }
        while(s.size()!=0){
            ans.insert(ans.begin(),s.top());
            s.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends