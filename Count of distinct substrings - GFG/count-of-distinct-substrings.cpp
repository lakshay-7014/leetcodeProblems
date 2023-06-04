//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends


/*You are required to complete this method */
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
    
    void insert(string word,int &cnt) {
        int i=0;
        trieNode* child=root;
        for(int i =0;i<word.size();i++){
            int index=word[i]-'a';
            if(child->children[index]!=NULL){
                child=child->children[index];
            }
            else{
                cnt++;
                trieNode* child1=new trieNode(word[i]);
                child->children[index]=child1;
                child=child1;
            }
        }
        child->isTerminal=true;
    }
   
};
int countDistinctSubstring(string s)
{
    //Your code here
    int cnt=0;
    Trie * t=  new Trie();
    for(int i=0;i<s.size();i++){
        string temp= s.substr(i);
        t->insert(temp,cnt);
        
    }
    return cnt+1;
}