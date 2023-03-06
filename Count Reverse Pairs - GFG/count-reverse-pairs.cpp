//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int ans=0;
    void merge(vector<int> &arr,int s ,int mid, int e){
    int l1= mid-s+1;
    int l2=e-mid;
    int *first=new int[l1];
    int *second=new int[l2];

    for(int i=0;i<l1;i++){
        first[i]=arr[s+i];
    }
    for(int i=0;i<l2;i++){
        second[i]=arr[mid+1+i];
    }
     int j1=0;
    for(int a=0;a<l1;a++){
        int cnt=0;
        while(j1<l2 && first[a]>2*second[j1]){
            j1++;
            cnt++;
        }
        ans+=(l1-a)*cnt;
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

void mergeSort1(vector<int> &arr,int s , int e){
    if(s>=e){
        return ;
    }
    int mid=s+(e-s)/2;
    mergeSort1(arr,s,mid);
    mergeSort1(arr,mid+1,e);
    merge(arr,s,mid,e);
}
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        int s=0;
        int e=n-1;
        mergeSort1(arr,s,e);
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends