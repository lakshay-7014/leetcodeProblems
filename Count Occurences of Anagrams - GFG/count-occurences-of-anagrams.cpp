//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> v1(26,0);
	    vector<int> v2(26,0);
	    for(auto&i : pat){
	       v1[i-'a']++;
	    }
	    int cnt=0;
	    int i=0;
	    for(int j=0;j<txt.size();j++){
	        if(v1[txt[j]-'a']==0){
	            vector<int> temp(26,0);
	            v2=temp;
	            i=j+1;
	            continue;
	        }
	        else{
	            v2[txt[j]-'a']++;
	            if(v1==v2){
	                cnt++;
	            }
	            else if(v2[txt[j]-'a'] > v1[txt[j]-'a']){
	                while(i<j && v2[txt[j]-'a']!=v1[txt[j]-'a']){
	                    v2[txt[i]-'a']--;
	                    i++;
	                }
	                if(v1==v2){
	                    cnt++;
	                }
	            }
	        }
	    }
	   return cnt;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends