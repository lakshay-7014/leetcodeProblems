class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        if(num==0){
            return true;
        }
        for(int i=0;i<num;i++){
            int x = i;
            int rev=0;
            int y=x;
            while(y!=0){
                int lastdig=y%10;
                rev=rev*10+lastdig;
                y=y/10;
            }
            if(x+rev == num ){
                return true;
            }
        }
        return false;
    }
};