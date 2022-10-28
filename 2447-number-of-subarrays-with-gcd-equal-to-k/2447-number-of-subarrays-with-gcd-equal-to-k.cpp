class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int i=0;
       int count=0;
        int n= nums.size();
        while(i<n){
             int j=i;
            int gcd=nums[i];
            while(j<n){
                gcd=__gcd(gcd,nums[j]);
                if(gcd==k){
                    count++;
                }
                if(gcd<k){
                    break;
                }
                j++;
            }
                i++;
        }
        return count;
    }
};