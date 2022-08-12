class Solution {
public:
    string convert(string s, int numRows) {
        string ans="";
        int n=s.length();
        int k=2*(numRows-2);
        if(n==1 || numRows==1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            int j=i;
            
            if(i==0 || i==numRows-1){
                while(j<n){
                    ans+=s[j];
                    j+=2*numRows-2;
                }
            }
            else{
                 while(j<n){
                    ans+=s[j];
                     if(j+k < n){
                         ans+=s[j+k];
                          //ans+=" ";
                     }
                    j+=2*numRows-2;
                }
                 k=k-2;
            }
           
        }
        return ans;
    }
};