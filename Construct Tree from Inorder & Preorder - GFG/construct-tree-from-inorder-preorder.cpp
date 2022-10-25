//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    
    
    public:
    void createMapping(int in[],map<int,int> &nodeToIndex ,int n){
        for(int i=0;i<n;i++){
            nodeToIndex[in[i]]=i;
        }
    }
    Node* solve(int in[],int pre[],int &index,map<int,int> &nodeToIndex,int inorderStart,int inorderEnd,int n ){
        if(index>=n || inorderStart >inorderEnd){
            return NULL;
        }
        int element=pre[index];
        index++;
        
        Node* root =new Node(element);
        int position=nodeToIndex[element];
        root->left=solve(in,pre,index,nodeToIndex,inorderStart,position-1,n);
        root->right=solve(in,pre,index,nodeToIndex,position+1,inorderEnd,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preorderIndex=0;
         map<int,int> nodeToIndex;
        createMapping(in,nodeToIndex,n);
        Node* ans=solve(in,pre,preorderIndex,nodeToIndex,0,n-1,n);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends