class Solution {
    private:
     void solve(int num,int &steps){
         if(num==0){
             return ;
         }
        if(num!=0 && num%2==0 ){
            steps++;
            solve(num/2,steps);
        }
         else if(num!=0 && num%2==1){
             steps++;
             solve(num-1,steps);
         }
         
     }
public:
    int numberOfSteps(int num) {
        int steps=0;
        solve(num , steps);
        return steps;
    }
};