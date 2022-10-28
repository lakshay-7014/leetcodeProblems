class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string s1=event1[0];
        string s2=event1[1];
        string s3= event2[0];
        string s4=event2[1];
        int fs1 = (s1[0]-'0')*10 + s1[1]-'0';
        int fs2= (s1[3]-'0')*10 + s1[4]-'0';
        fs1=fs1*100 + fs2;
        
        int fe1= (s2[0]-'0')*10 + s2[1]-'0';
        int fe2=(s2[3]-'0')*10 + s2[4]-'0';
        
        fe1=fe1*100 +fe2;
        
        int ss1=(s3[0]-'0')*10 + s3[1]-'0';
        int ss2=(s3[3]-'0')*10 + s3[4]-'0';
        
        ss1=ss1*100 +ss2;
        
        int se1=(s4[0]-'0')*10 + s4[1]-'0';
        int se2=(s4[3]-'0')*10 + s4[4]-'0';
        
        se1=se1*100 + se2;
        
        if(ss1>=fs1 && ss1<=fe1){
            return true;
        }
        if(se1>=fs1 && se1<=fe1){
            return true;
        }
        if(fs1> ss1 && fe1< se1){
            return true;
        }
        
        return 0;
    }
};