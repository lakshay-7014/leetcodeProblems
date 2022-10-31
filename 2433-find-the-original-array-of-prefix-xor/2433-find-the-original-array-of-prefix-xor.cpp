class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans;
        int a = pref[0];
        ans.push_back(a);
        int n = pref.size();
        if(n==1){
            return ans;
        }
        for(int i=1;i<n;i++){
            int val = a ^ pref[i];
            ans.push_back(val);
            a=a^ans[i];
        }
        return ans;
    }
};