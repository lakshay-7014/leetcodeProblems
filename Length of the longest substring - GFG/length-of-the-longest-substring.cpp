//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        //unordered_map<char,int> mp;
        vector<int> mp(26,0);
        int i=0;
        int j=0;
        int n = s.size();
        int ans=0;
        
        while(j<n){
            if(mp[s[j]-'a']==0){
                mp[s[j]-'a']++;
                j++;
            }
            else{
                ans=max(ans,j-i);
                while(mp[s[j]-'a']!=0){
                    mp[s[i]-'a']--;
                    i++;
                }
                mp[s[j]-'a']++;
                j++;
            }
        }
        ans=max(ans,j-i);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends