class Solution {
    private:
    void solve(string digit,string output,int index,vector<string>& ans,string map[]){
        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }
        int number=digit[index]-'0';
        string value=map[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digit,output,index+1,ans,map);
            output.pop_back(); // to make output string empty again 
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output="";
        int index=0;
        if(digits.length()==0){
            return ans;
        }
    string map[10]{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,map);
        return ans;
    }
};