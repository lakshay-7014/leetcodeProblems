//{ Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* subLinkedList(Node* l1, Node* l2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        
        Node* res = subLinkedList(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends

#include<bits/stdc++.h>
/* Structure of linked list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

*/

//You are required to complete this method

Node* subLinkedList(Node* l1, Node* l2)
{
    //Your code here
    Node* curr1=l1;
    Node* curr2=l2;
    
    vector<int> v1;
    vector<int> v2;
    
    while(curr1!=NULL && curr1->data==0){
        curr1=curr1->next;
    }
    while(curr2!=NULL && curr2->data==0){
        curr2=curr2->next;
    }
    
    while(curr1!=NULL){
        v1.push_back(curr1->data);
        curr1=curr1->next;
    }
    while(curr2!=NULL){
        v2.push_back(curr2->data);
        curr2=curr2->next;
    }
    
    int i = -1;
    int j= -1;
    //cout<<v2.size()<<" ";
    if((int)v1.size()>(int)v2.size()){
        i=v1.size()-1;
        j=v2.size()-1;
        
    }
    else if((int)v1.size()<(int)v2.size()){
        i=v2.size()-1;
        j=v1.size()-1;
        swap(v1,v2);
    }
    else{
        //cout<<"gg";
        for(int i1=0;i1<v1.size();i1++){
            if(v1[i1]==v2[i1]){
                continue;
            }
            else if(v1[i1]>v2[i1]){
                i=v1.size()-1;
                j=v2.size()-1;
                break;
            }
            else{
                
                i=v2.size()-1;
                j=v1.size()-1;
                swap(v1,v2);
                break;
            }
        }
    }
   // cout<<v1[i]<<" ";
   // cout<<j ;
    Node* ans=NULL;
    while(i>=0 && j>=0){
        if(v1[i]>=v2[j]){
            int diff= v1[i]-v2[j];
           // cout<<diff<<" ";
            Node* temp= new Node(diff);
            if(ans==NULL){
                ans=temp;
            }
            else{
                temp->next=ans;
                ans=temp;
            }
        }
        else if(v1[i]<v2[j]){
            v1[i]=10 + v1[i];
            if(i-1>=0 && v1[i-1]==0){
                int idx=i-1;
                while(idx>=0 && v1[idx]==0){
                    v1[idx]=9;
                    idx--;
                }
                if(idx>=0){
                    v1[idx]--;
                }
            }
            else if(i-1>=0 ){
                v1[i-1]--;
            }
            int diff= v1[i]-v2[j];
             //cout<<diff<<" ";
            Node* temp= new Node(diff);
            if(ans==NULL){
                ans=temp;
            }
            else{
                temp->next=ans;
                ans=temp;
            }
            
        }
        i--;
        j--;
    }
    //cout<<ans->data<<" ";
    while(i>=0){
        Node* temp= new Node(v1[i]);
            if(ans==NULL){
                ans=temp;
            }
            else{
                temp->next=ans;
                ans=temp;
            }
            i--;
    }
    while(ans!=NULL && ans->data==0){
        ans=ans->next;
    }
    if(ans==NULL){
        Node* temp = new Node(0);
        return temp;
    }
    return ans;
    
    
    
    
}