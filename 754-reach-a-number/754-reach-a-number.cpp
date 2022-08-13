class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
      int sum=0;
        int mov=0;
        int i=1;
        while(sum<target){
            sum+=i;
            mov++;
            i++;
        }
        while((sum-target)%2!=0){
            sum+=i;
            mov++;
            i++;
        }
        return mov;
    }
};