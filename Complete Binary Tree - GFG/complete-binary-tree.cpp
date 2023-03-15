//{ Driver Code Starts
// A program to check if a given binary tree is complete or not
#include<bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
    

class Solution{
public:    
    bool isCompleteBT(Node* root){
        //code here
         queue<Node*>  q;
       q.push(root);
       q.push(NULL);
       vector<int> v;
       v.push_back(root->data);
       while(q.size()>0){
           Node* fr= q.front();
           q.pop();
           if(fr==NULL){
               if(q.size()!=0){
                   q.push(NULL);
               }
               else{
                   break;
               }
           }
           else{
               if(fr->left!=NULL){
                   v.push_back(fr->left->data);
                   q.push(fr->left);
               }
               else{
                   v.push_back(-1);
               }
               if(fr->right!=NULL){
                   v.push_back(fr->right->data);
                   q.push(fr->right);
               }
               else{
                   v.push_back(-1);
               }
           }
       }
       bool flag=false;
       for(int i=0;i<v.size();i++){
           if(v[i]==-1){
               flag=true;
           }
           else if(flag==true && v[i]!=-1){
               return false;
           }
       }
       return true;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ",&t);
    while(t--)
    {
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
		Solution ob;
        if(ob.isCompleteBT(root)){
            printf ("Complete Binary Tree\n");
        }
        else{
            printf ("Not Complete Binary Tree\n");
        } 
    }
    return 0;
}





// } Driver Code Ends