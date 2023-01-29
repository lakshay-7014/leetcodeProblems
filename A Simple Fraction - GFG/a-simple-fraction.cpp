//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int num, int den) {
	    // Code here
	    string ans="";
         if(num==0){
             return "0";
         }
         if(num<0 || den<0 ){
             if(num < 0 && den>=0){
                 ans+='-';
             }
             else if(den<0 && num>=0){
                 ans+='-';
             }
         }
        den=abs(den);
        num=abs(num);
        long long div=abs(num/den);
        long long rem=abs(num%den);
         ans+=to_string(div);

        if(rem==0){
            return ans;
        }
         ans+=".";
        unordered_map<long long,int> mp;
        while(rem!=0){
            if(mp.find(rem)!=mp.end()){
                int idx=mp[rem];
                ans.insert(idx,"(");
                ans+=')';
                break;
            }
            else{
                mp[rem]=ans.size();
                rem=rem*10;
                div=rem/den;
                rem=rem%den;
                ans+=to_string(div);
            }
        }
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends