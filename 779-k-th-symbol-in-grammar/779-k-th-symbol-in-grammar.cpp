class Solution {
public:
    bool solve(int n , int k){
        if(n==1 && k==1){
            return 0;
        }
        int length=pow(2,n-1);
        length=length/2;
        if(k<=length){
            return solve(n-1,k);
        }
        else{
            return !solve(n-1,k-length);
        }
    }
    int kthGrammar(int n, int k) {
        return solve(n,k);
    }
};