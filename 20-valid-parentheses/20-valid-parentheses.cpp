class Solution {
public:
    bool isValid(string s) {
        int flag=0;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]== '(' ){
                if(s[i+1]==')'){
                    s.erase(i,2);
                }
                else{
                    flag=1;
                    break;
                }
            }
            else if(s[i]== '['){
                if(s[i+1]==']'){
                    s.erase(i,2);
                }
                else{
                    flag=1;
                    break;
                }
            }
            else if(s[i]== '{'){
                if(s[i+1]=='}'){
                    s.erase(i,2);
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        int n=s.length();
        if(flag==0 && n==0){
            return 1;
        }
        else{
            return 0;
        }
        return 0;
    }
};