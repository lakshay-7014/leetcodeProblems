//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class trieNode{
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;
    trieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal = false;
    }
};
class Trie {
public:
    trieNode* root;
    Trie() {
        root= new trieNode('\0');
    }
    
    void insert(string word) {
        int i=0;
        trieNode* child=root;
        for(int i =0;i<word.size();i++){
            int index=word[i]-'a';
            if(child->children[index]!=NULL){
                child=child->children[index];
            }
            else{
                trieNode* child1=new trieNode(word[i]);
                child->children[index]=child1;
                child=child1;
            }
        }
        child->isTerminal=true;
    }
    
    void search(string s , string &ans){
        trieNode*child=root;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(child->children[s[i]-'a'] !=NULL){
                temp+=s[i];
                child=child->children[s[i]-'a'];
            }
            else{
                break;
            }
        }
        int sz=temp.size();
        int n =ans.size();
        if(sz==0){
            ans="";
        }
        else if(sz<n){
            ans=temp;
        }
        return ;
    }
    
    
   
};
class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string ans=arr[0];
        Trie * t = new Trie();
        t->insert(arr[0]);
        
        for(int i=1;i<N;i++){
            string s= arr[i];
            t->search(s,ans);
        }
        if(ans.size()==0){
            return "-1";
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends