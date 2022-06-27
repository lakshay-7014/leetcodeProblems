class Solution {
public:
    char findTheDifference(string s, string t) {
        int n1=s.length();
        int n2=t.length();
        if(n1==0){
            return t[0];
        }
        char ans= s[0];
        for(int i=1;i<n1;i++){
            ans=ans^s[i];
        }
        for(int i=0;i<n2;i++){
            ans=ans^t[i];
        }
        return ans;
    }
};