class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        vector<char> ans;
        int i=0;
        int index=0;
        while(i<n){
            int j=i+1;
             ans.push_back(chars[i]);
            while(j<n && chars[i]==chars[j] ){
                j++;
            }
            //chars[index++]=chars[i];
           
            int count =j-i;
            if(count>1){
                string cnt=to_string(count);
                for(int i=0;i<cnt.length();i++){
                    //chars[index++]=cnt[i];
                     ans.push_back(cnt[i]);
                }
            }
            i=j;
        }
        chars.clear();
        chars=ans;
        return chars.size();
    }
};
