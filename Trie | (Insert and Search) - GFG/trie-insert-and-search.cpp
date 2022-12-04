//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>

using namespace std;

// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;

    pNode = (struct TrieNode *) malloc(sizeof(struct TrieNode));

    if (pNode) {
        int i;

        pNode->isLeaf = false;

        for (i = 0; i < ALPHABET_SIZE; i++) pNode->children[i] = NULL;
    }

    return pNode;
}

void insert(struct TrieNode *, string);

bool search(struct TrieNode *, string);

// Driver
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        // Input keys (use only 'a' through 'z' and lower case)
        int n;
        cin >> n;
        string keys[n];

        for (int i = 0; i < n; i++) {
            cin >> keys[i];
        }

        struct TrieNode *root = getNode();
        // Construct trie
        for (int i = 0; i < n; i++) insert(root, keys[i]);

        string abc;

        cin >> abc;
        // Search for different keys

        if (search(root, abc))
            cout << "1\n";
        else
            cout << "0\n";
        // char ex;
        // cin >> ex;
        // cout << ex << "\n";
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// trie node
/*
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    // isLeaf is true if the node represents
    // end of a word
    bool isLeaf;
};
*/

//Function to insert string into TRIE.

void insertUtil(TrieNode* root,string word,int i){
        if(i==word.length()){
            root->isLeaf=true;
            return;
        }
        int index=word[i]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child= getNode();
            root->children[index]=child;
        }
        i++;
        insertUtil(child,word,i);
        
    }
void insert(struct TrieNode *root, string key)
{
    // code here
     int i=0;
    insertUtil(root,key,i);
}

//Function to use TRIE data structure and search the given string.
bool searchUtil(TrieNode* root,string word,int i){
        if(i==word.length()){
            return root->isLeaf;
        }
        int index=word[i]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
             child=root->children[index];
        }
        else{
            return false;
        }
        i++;
        return searchUtil(child,word,i);
        
    }
bool search(struct TrieNode *root, string key) 
{
    // code here
      int i = 0;
       return searchUtil(root, key, i);
}