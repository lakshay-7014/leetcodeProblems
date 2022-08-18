class Solution {
    void solve(vector<int> &ans, int index,int k,int &size){
        if(size==1){
            return ;
        }
        index=(index+k-1) % size;
        ans.erase(ans.begin()+index);
        size=ans.size();
        solve(ans,index, k, size);
        
    }
public:
    int findTheWinner(int n, int k) {
        if(n==1){
            return 1;
        }
        vector<int> ans;
        int index=0;
        for(int i=1;i<=n;i++){
            ans.push_back(i);
        }
        int size=ans.size();
        solve(ans,index,k,size);
        
        return ans[0];
    }
};
