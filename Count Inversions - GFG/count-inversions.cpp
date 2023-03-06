//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long ans=0;
    
    void merge(long long arr[],int s ,int mid, int e){
    int l1= mid-s+1;
    int l2=e-mid;
    long long *first=new long long[l1];
    long long *second=new long long[l2];

    for(int i=0;i<l1;i++){
        first[i]=arr[s+i];
    }
    for(int i=0;i<l2;i++){
        second[i]=arr[mid+1+i];
    }

    int i=0;
    int j=0;
    int k=s;

    while(i<l1 && j<l2){
        if(first[i]<=second[j]){
            arr[k]=first[i];
            i++;
            k++;
        }
        else{
            ans+=l1-i;
            arr[k]=second[j];
            j++;
            k++;
        }
    }
    while(i<l1){
        arr[k]=first[i];
        i++;
        k++;
    }
    while(j<l2){
        arr[k]=second[j];
        j++;
        k++;
    }

    delete first;
    delete second;

}

void mergeSort1(long long arr[],int s , int e){
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;
    mergeSort1(arr,s,mid);
    mergeSort1(arr,mid+1,e);
    merge(arr,s,mid,e);
}
    long long int inversionCount(long long arr[], long long N)
    {
        int s=0;
        int e=N-1;
        mergeSort1(arr,s,e);
        return ans;
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends