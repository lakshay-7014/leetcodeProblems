class Solution {
public:
    int romanToInt(string s) {
        map<char,int> ans;
        // insert elements in random order
    ans.insert(pair<char, int>('I', 1));
    ans.insert(pair<char, int>('V', 5));
    ans.insert(pair<char, int>('X', 10));
    ans.insert(pair<char, int>('L', 50));
    ans.insert(pair<char, int>('C', 100));
    ans.insert(pair<char, int>('D', 500));
    ans.insert(pair<char, int>('M', 1000));
        int sum=0;
        int i=0;
        int size=s.length();
        while(i<=size-1){
            if(ans[s[i]]>=ans[s[i+1]]){
                sum+=ans[s[i]];
            }
            else{
                sum+= ans[s[i+1]]-ans[s[i]];
                i++;
            }
           // cout<<sum<<" ";
            i++;
        }
        if(i<size-1){
            sum+=ans[s[i]];
            i++;
        }
        return sum;
    }
};