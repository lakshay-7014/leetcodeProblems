#include <stack>
#include <vector>
class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.length()-1;
        while(n>=0){
            stack<char> s1;
            //string temp="";
             while(n>=0 && s[n]==' '){
                n--;
            }
            while(n>=0 &&s[n]!=' ' && s[n]!='\0'){
                s1.push(s[n]);
                n--;
            }
            while(n>=0 && s[n]==' '){
                n--;
            }
           char ap=' ';
            s1.push(ap);
            while(s1.size()!=0){
               char c=s1.top();
                ans+=c;
                s1.pop();
            }
            if(n<0){
                break;
            }
        }
        ans.erase(0,1);
        return ans;
    }
};