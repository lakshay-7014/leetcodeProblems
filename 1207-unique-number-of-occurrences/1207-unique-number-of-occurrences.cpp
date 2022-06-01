class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int count=1;
        vector<int> ans;
        int n=arr.size();
        int i=0;
        int j=0;
        while(i<n){
            for( j=i;j<n-1;j++){
                if(arr[j]==arr[j+1]){
                    count++;
                }
                else{
                    break;
                }
            }
            ans.push_back(count);
            count=1;
           i=j+1;
            
        }
        sort(ans.begin(),ans.end());
        
        int x=ans.size();
        for(int i=0;i<x-1;i++){
            if(ans[i]==ans[i+1]){
                return 0;
            }
        }
        return 1;
    }
};