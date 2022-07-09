class Solution {
public:
    bool validPalindrome(string s) {
        int st=0;
        int e=s.length()-1;
        int flag=0;
        int flag1=0;
        while(st<e){
            if(flag==0 && s[st]!=s[e]){
                flag=1;
                st++;
            }
            else if(s[st]!=s[e]){
                flag=2;
                break;
            }
            else{
                st++;
                e--;
            }
        }
        st=0;
        e=s.length()-1;
        while(flag==2 && st<e){
            if(flag1==0 && s[st]!=s[e]){
                flag1=1;
                e--;
            }
            else if(s[st]!=s[e]){
                return false;
            }
            else{
                swap(s[st],s[e]);
                st++;
                e--;
            }
        }
        return true;
    }
};