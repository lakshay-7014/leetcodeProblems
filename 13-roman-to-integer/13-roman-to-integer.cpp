int value(char c){
    if(c=='I'){
        return 1;
    }else if(c=='V'){
        return 5;
    }else if(c=='X'){
        return 10;
    }else if(c=='L'){
        return 50;
    }else if(c=='C'){
        return 100;
    }else if(c=='D'){
        return 500;
    }else if(c=='M'){
        return 1000;
    }
    return 0;
}

class Solution {
public:
    int romanToInt(string s) {
        vector<int>v;
        int ans=0;
        int i=0;
        while(s[i]!='\0'){
            if(value(s[i])>=value(s[i+1])){
                ans+=value(s[i]);
            }else{
                ans-=value(s[i]);
            }
            i++;
            
        }
        
        return ans;
    }
};