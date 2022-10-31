class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        map<int,int> mp1;
        map<int,int> mp2;
        int row= logs.size();
        int s=0;
        int maxi=0;
        int ans =INT_MAX;
        for(int i=0;i<row;i++){
            int e= logs[i][1];
            mp1[i]= e-s;
            s=e;
            mp2[i]=logs[i][0];
        }
        
        for(int i=0;i<row;i++){
            int val= mp1[i];
            maxi=max(maxi,val);
            
        }
        for(int i=0;i<row;i++){
            if(mp1[i]==maxi){
                int id = mp2[i];
                ans=min(ans,id);
            }
        }
        return ans;
        
    }
};