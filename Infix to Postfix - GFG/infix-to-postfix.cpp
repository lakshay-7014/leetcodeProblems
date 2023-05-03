//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string in) {
        // Your code here
        //left to right scan kroo
        string ans="";
        stack<char> s;
        for(int i=0;i<in.size();i++){
            if((in[i]>='a' && in[i]<='z') || (in[i]>='A' && in[i]<='Z')){
                ans+=in[i];
            }
            else if(in[i]>='0' && in[i]<='9'){
                ans+=in[i];
            }
            else if(in[i]=='('){
                s.push(in[i]);
            }
            else if(in[i]=='^'){
                
                while(s.size()!=0 && s.top()=='^'){
                    ans+=s.top();
                    s.pop();
                }
                s.push(in[i]);
            }
            else if(in[i]=='+'){
                if(s.size()==0){
                    s.push(in[i]);
                }
                else{
                    while(s.size()!=0 && s.top()!='('){
                    ans+=s.top();
                    s.pop();
                }
                s.push(in[i]);
              }
            }
            else if(in[i]=='-'){
                if(s.size()==0){
                    s.push(in[i]);
                }
                else{
                    while(s.size()!=0 && s.top()!='('){
                    ans+=s.top();
                    s.pop();
                    
                }
                s.push(in[i]);
              }
            }
            else if(in[i]==')'){
                while(s.top()!='('){
                    ans+=s.top();
                    s.pop();
                }
                s.pop();
            }
            else if(in[i]=='*'){
                if(s.size()==0){
                    s.push(in[i]);
                }
                else if(s.top()=='^' || s.top()=='/' || s.top()=='*'){
                    while(s.size()!=0 &&(s.top()!='(' ) &&(s.top()=='^' || s.top()=='*' || s.top()=='/')){
                        ans+=s.top();
                        s.pop();
                    }
                    s.push(in[i]);
                }
                else{
                    if(s.top()=='('){
                        s.push(in[i]);
                    }
                    else if(s.top()=='+' || s.top()=='-'){
                        s.push(in[i]);
                    }
                }
            }
            else if(in[i]=='/'){
                 if(s.size()==0){
                    s.push(in[i]);
                }
                else if(s.top()=='^' || s.top()=='/' || s.top()=='*'){
                    while(s.size()!=0 &&(s.top()!='(' ) &&(s.top()=='^' || s.top()=='*' || s.top()=='/')){
                        ans+=s.top();
                        s.pop();
                    }
                    s.push(in[i]);
                }
                else{
                    if(s.top()=='('){
                        s.push(in[i]);
                    }
                    else if(s.top()=='+' || s.top()=='-'){
                        s.push(in[i]);
                    }
                }
            }
            
        }
        while(s.size()!=0){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
    
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends