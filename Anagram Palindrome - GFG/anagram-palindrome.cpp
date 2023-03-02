//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    vector<int> freq(26,0);
    for(int i=0;i<S.size();i++){
        freq[S[i]-'a']++;
    }
    bool flag=false;
    for(int i=0;i<26;i++){
        if(freq[i]==0){
            continue;
        }
        else if(freq[i]%2==0){
            continue;
        }
        else if(flag==false && freq[i]%2!=0){
            flag=true;
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}