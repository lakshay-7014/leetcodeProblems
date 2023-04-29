//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* solve(Node* root,int target){
        if(root==NULL){
            return NULL;
        }
        Node* left= solve(root->left,target);
        Node* right= solve(root->right,target);
        if(root->data==target){
            return root;
        }
        if(left!=NULL){
            return left;
        }
        if(right!=NULL){
            return right;
        }
        return NULL;
    }
    
    void solve2(Node* root,unordered_map<Node*,Node*> &mp,Node* parent){
     if(root==NULL){
       return ;
     }
     if(parent!=NULL){
       mp[root]=parent;
     }

     solve2(root->left,mp,root);
     solve2(root->right,mp,root);

   }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        
        Node* temp = solve(root,target);
        unordered_map<Node*,Node*> mp;
        solve2(root,mp,NULL);
        
        
        queue<Node*> q;
        q.push(temp);
        int t=0;
        unordered_map<Node*,bool> vis;
        while(q.size()!=0){
            int sz= q.size();
            bool flag=false;
            for(int i=0;i<sz;i++){
                Node* fr= q.front();
                q.pop();
                vis[fr]=true;
                if(fr!= root && vis[mp[fr]]==false){
                    q.push(mp[fr]);
                    flag=true;
                }
                if(fr->left && vis[fr->left]==false){
                    q.push(fr->left);
                    flag=true;
                }
                if(fr->right && vis[fr->right]==false){
                    q.push(fr->right);
                    flag=true;
                }
            }
            if(flag==true){
             t++;
            }
        }
        
        return t;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends