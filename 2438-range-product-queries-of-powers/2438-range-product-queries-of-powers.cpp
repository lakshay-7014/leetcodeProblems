class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> ans;
        
        if((n&(n-1))== 0 ){
            powers.push_back(n);
        }
        else{
            int sum=n;
            while(sum!=0){
                int val=1;
                while(true){
                    if(val<=sum){
                         val*=2;
                    }
                    else{
                        val=val/2;
                        break;
                    }
                }
                powers.push_back(val);
                sum=sum-val;
            }
           
        }
        reverse(powers.begin(),powers.end());
       
        int n1= queries.size();
        for(int j=0;j<n1;j++){
            if(queries[j][0]!=queries[j][1]){
                int pow=1;
                for(int k = queries[j][0] ; k<= queries[j][1];k++){
                    pow=(pow *1LL *  powers[k]) % int(1e9 + 7);
                }
                ans.push_back(pow);
            }
            else{
                ans.push_back(powers[queries[j][0]]);
            }
        }
        return ans;
    }
};