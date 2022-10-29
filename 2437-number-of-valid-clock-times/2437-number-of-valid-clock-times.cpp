class Solution {
public:
    int countTime(string time) {
        int first=1;
        int second=1;
       
        if(time[0]=='?'){
            if(time[1]=='?' ){
                first=24;
            }
            else if(time[1]>='4' && time[1]<='9'){
                first=2;
            }
            else if(time[1]>='0' && time[1]<='3'){
                first=3;
            }
           
        }
        if(time[1]=='?'){
            if(time[0]=='0' || time[0]=='1'){
                first=10;
            }
            else if(time[0]=='2'){
                first=4;
            }
        }
        
        if(time[3]=='?'){
            if(time[4]=='?'){
                second=60;
            }
            else if(time[4]>='0' && time[4]<='9'){
                second=6;
            }
        }
        if(time[4]=='?'){
            if(time[3]>='0' && time[3]<='5'){
                second=10;
            }
        }
        int ans= first * second;
        return ans;
    }
};