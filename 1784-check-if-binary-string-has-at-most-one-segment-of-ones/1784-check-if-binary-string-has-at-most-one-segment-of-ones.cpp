class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.length();
        int index=-1;
        int flag=0;
        if(n==1){
               return true;
        }
        for(int i=0;i<n;i++){
           if(s[i]=='0'){
               index=i;
               break;
           }   
        }
        if(index!=n-1 && index!=-1){
        for(int i=index;i<n;i++){
            if(s[i]=='1'){
                flag=1;
                return false;
            }
        }
        }
        if(flag==0){
            return true;
        }
         return true;
    }
};