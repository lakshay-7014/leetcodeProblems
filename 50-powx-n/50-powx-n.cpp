class Solution {
    double power(double x,int n){
       // x^n a^b
        double res=1;
        while(n>0){
            if(n%2==1){
                res=res*x;
            }
            x= (x*x);
            n=n>>1;
        }
        return res;
    }
public:
    double myPow(double x, int n) {
       
       
        double ans= power(x,n);
       if(n>=0){
           return power(x,n);
       }
        return 1/power(x,abs(n));
        
       
    }
};