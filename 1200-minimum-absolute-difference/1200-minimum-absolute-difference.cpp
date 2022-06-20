class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
       sort(arr.begin(),arr.end());
      
       int n=arr.size()-1;
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i+1]-arr[i]<min){
                min=arr[i+1]-arr[i];
            }
        }
        cout<<min;
         vector<vector<int>> ans;
         for(int i=0;i<n;i++){
           vector<int> temp;
             if(arr[i+1]-arr[i]==min){
                 temp.push_back(arr[i]);
                  temp.push_back(arr[i+1]);
                 ans.push_back(temp);
                temp.clear();
             }
            
        }
        return ans;
    }
};