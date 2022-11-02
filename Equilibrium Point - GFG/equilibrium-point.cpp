//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1){
            return 1;
        }
        int s=0;
        int e=n-1;
        int sum1=a[0];
        int sum2=a[n-1];
        while(s<e){
            if(sum1<sum2){
                s++;
                sum1+=a[s];
            }
            else if(sum1>sum2){
                e--;
                sum2+=a[e];
            }
            else{
                s++;
                e--;
                sum1+=a[s];
                sum2+=a[e];
                if(s==e){
                    return s+1;
                }
            }
        }
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends