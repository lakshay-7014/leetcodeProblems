class Solution {
    private:
    void solve(vector<string> &ans,string output,string mapping[],int index,string digits ){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int dig=digits[index]-'0';
        string value=mapping[dig];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(ans,output,mapping,index+1,digits);
            output.pop_back(); //****important step
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.length()==0){
            return ans;
        }
        
        string output="";
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        solve(ans,output,mapping,index, digits);
        return ans;
    }
};