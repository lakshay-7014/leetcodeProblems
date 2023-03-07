//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int pivot(int A[],int s ,int e){
        int mid=s+(e-s)/2;
        while(s<e){
            int elem=A[mid];
            if(elem<A[0]){
                e=mid;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return mid;
    }
    
    int binary(int arr[],int s , int e , int target){
        int mid=s+(e-s)/2;
        while(s<=e){
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            mid=s+(e-s)/2;
        }
        return -1;
    }
    int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int piv= pivot(A,l,h);
        if(key>=A[piv] && key<=A[h]){
            return binary(A,piv,h,key);
        }
        
        return binary(A,0,piv-1,key);
        
    
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends