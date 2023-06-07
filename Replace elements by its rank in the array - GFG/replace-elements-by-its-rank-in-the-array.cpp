//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<int ,vector<int> , greater<int>> pq;
        
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        int cnt=1;
        
        map<int,int> mp;
        while(pq.size()!=0){
            int elem=pq.top();
            pq.pop();
            if(mp.find(elem)==mp.end()){
                mp[elem]=cnt;
                cnt++;
            }
            else{
                mp[elem]=cnt-1;
            }
            
        }
        
        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }
        return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends