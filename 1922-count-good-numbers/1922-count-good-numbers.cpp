class Solution {
    private:
     long long power(long long x,long long n){
       // x^n a^b
        long long mod=1000000007;
        long long res=1;
        while(n>0){
            if(n%2==1){
                res=(res*x)%mod ;
            }
            x= (x*x)%mod ;
            n=n>>1;
        }
        return res;
    }
public:
    int countGoodNumbers(long long n) {
        long long mod=1000000007;
        long long a=(n+1)/2;
        long long b=(n)/2;
        long long first=power(5,a);
        long long second=power(4,b);
        first=(first * second)%mod;
        int ans=first;
        return ans;
        
    }
};