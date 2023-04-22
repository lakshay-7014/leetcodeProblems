//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	  set<string> ans;
	  int solve(string &s1, string &s2, int x , int y , int i , int j ,vector<vector<int>> &dp){
        if(i>=x || j>=y){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return 1 + solve(s1,s2,x,y,i+1,j+1,dp);
        }
        
        int ans = max(solve(s1,s2,x,y,i+1,j,dp),solve(s1,s2,x,y,i,j+1,dp));
        
        return dp[i][j]=ans;
    }
    void solve2(int x , int y , string temp,string &s1,string &s2,int len){
        if(len==0){
            ans.insert(temp);
            return ;
        }
        
        for(int i= x ;i < s1.size();i++){
            for(int j=y;j<s2.size();j++){
                if(s1[i]==s2[j]){
                    solve2(i+1,j+1,temp+s1[i],s1,s2,len-1);
                }
            }
        }
        
    }
    
		vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		    // Code here
		    int x= s1.size();
		    int y= s2.size();
		    vector<vector<int>> dp(x+1,vector<int>(y+1,-1));
            int len=solve(s1,s2,x,y,0,0,dp);
            
            string temp="";
            
            solve2(0,0,temp,s1,s2,len);
            
            vector<string> res;
            for(auto &i : ans){
                res.push_back(i);
            }
            return res;
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends