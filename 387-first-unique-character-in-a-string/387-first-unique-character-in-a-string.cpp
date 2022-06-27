class Solution {
public:
    int firstUniqChar(string s) {
         vector<int> ans(26,0);
        int n=s.length();
        for(int i=0;i<n;i++){
            int a=s[i]-'a';
            ans[a]=ans[a]+1;
        }
        for(int i=0;i<n;i++){
            int b=s[i]-'a';
            if(ans[b]==1){
                return i;
            }
        }
        return -1;
    }
};