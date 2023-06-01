//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int s, int mid, int e)
    {
         // Your code here
         int *first= new int[mid-s+1];
         int *second= new int[e-mid];
        
         for(int i=0;i<(mid-s+1);i++){
             first[i]=arr[s+i];
         }
         for(int i=0;i<(e-mid);i++){
             second[i]=arr[mid+1+i];
         }
         int i=0;
         int j=0;
         int k=s;
         int n = mid-s+1;
         int m = e-mid;
         
         while(i<n && j<m){
             if(first[i]<second[j]){
                 arr[k]=first[i];
                 i++;
             }
             else{
                 arr[k]=second[j];
                 j++;
             }
             k++;
         }
         while(i<n){
             arr[k]=first[i];
             i++;
             k++;
         }
         while(j<m){
             arr[k]=second[j];
             j++;
             k++;
         }
         
         delete first;
         delete second;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r){
            return ;
        }
        int mid=l+(r-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends