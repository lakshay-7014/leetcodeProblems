class Solution {
public:
    int maximum69Number (int num) {
        stack<int> s;
        while(num>0){
            int lastdig= num%10;
            s.push(lastdig);
            num=num/10;
        }
        int ans=0;
        bool flag= true;
        while(s.size()!=0){
            int elem =s.top();
            s.pop();
            if(elem==9){
                ans=ans*10+elem;
            }
            else if(flag==true){
                ans=ans*10+ 9;
                flag =false;
            }
            else{
                 ans=ans*10+elem;
            }
        }
        return ans;
    }
};