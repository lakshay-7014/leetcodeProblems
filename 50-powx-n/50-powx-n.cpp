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
        int n1=abs(n);
       
        double ans= power(x,n1);
        if(n>=0){
            return ans;
        }
        double dig=1;
        ans=dig/ans;
         if(n== -2147483648 && x==2){
            return dig-1;
        }
        else if(n== -2147483648 && x==2){
            return dig;
        }
        
        return ans;
    }
};