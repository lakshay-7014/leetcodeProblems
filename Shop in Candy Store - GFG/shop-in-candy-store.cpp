//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> ans;
        sort(candies,candies+N);
        int mini=0;
        int st=0;
        int end=N-1;
        while(st<=end){
            mini+=candies[st];
            end=end-K;
            st++;
        }
        
        int maxi=0;
        st=0;
        end=N-1;
        while(st<=end){
            maxi+=candies[end];
            st=st+K;
            end--;
        }
        
        return {mini,maxi};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends