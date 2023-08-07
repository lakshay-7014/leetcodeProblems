//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string s)
	{
	    // Your code goes here
	    int n =s.size();
	    
	    int ans=-1;
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        if(s[i]=='0'){
	            cnt++;
	            ans=max(ans,cnt);
	        }
	        else{
	            if(cnt==0){
	                continue;
	            }
	            cnt--;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends