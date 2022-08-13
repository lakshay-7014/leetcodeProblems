class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length()-1;
        int n2=num2.length()-1;
        int carry=0;
        int i=0;
        string  ans="";
        while(n1>=0 && n2>=0){
            int a1=num1[n1]-'0';
            int a2=num2[n2]-'0';
             int sum=(a1+a2+carry)%10;
           
            ans+=(sum+'0') ;
            carry= (a1+a2+carry)/10;
            n1--;
            i++;
            n2--;
        }
        while(n1>=0){
            int a1=num1[n1]-'0';
             int sum= (a1 + carry)%10;
            ans+=(sum+'0') ;
            carry= (a1+carry)/10;
            n1--;
            i++;
        }
        while(n2>=0){
            int a2=num2[n2]-'0';
            int sum= (a2 + carry)%10;
           ans+=(sum + '0');
            carry= (a2+carry)/10;
            n2--;
            i++;
        }
        if(carry!=0){
            ans+=(carry+'0') ;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};