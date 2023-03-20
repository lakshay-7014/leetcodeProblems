//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*
The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        
        Node* prev=NULL;
        Node* curr=head;
        Node* nex=curr ;
        
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        curr=prev;
        Node* rev = prev;
        
        int value=curr->data;
        nex=curr->next;
        while(nex!=NULL){
            if(nex->data< value){
                Node* temp=nex;
                if(nex->next!=NULL){
                    curr->next=nex->next;
                }
                else{
                    curr->next=NULL;
                }
                nex=nex->next;
                temp->next=NULL;
                delete temp;
            }
            else{
                value=nex->data;
                curr=nex;
                nex=nex->next;
            }
        }
        
        curr=rev;
        prev=NULL;
        nex=curr;
        while(curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        
        return prev;
        
    }
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends