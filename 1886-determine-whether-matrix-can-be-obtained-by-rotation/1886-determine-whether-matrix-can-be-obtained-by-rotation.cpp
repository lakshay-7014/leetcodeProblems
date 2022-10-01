class Solution {
    void solve(vector<vector<int>> &res,vector<vector<int>>& mat,int row , int col){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                res[j][row-1-i]=mat[i][j];
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                mat[i][j]=res[i][j];
            }
        }
        return;
    }
    bool check(vector<vector<int>> res,vector<vector<int>>& target,int row,int col){
         for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(res[i][j]!=target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target){
            return true;
        }
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> res(row,vector<int>(col,0));
        solve(res,mat,row,col);
        if(check(res,target,row,col)){
            return true;
        }
        solve(res,mat,row,col);
        if(check(res,target,row,col)){
            return true;
        }
        solve(res,mat,row,col);
        if(check(res,target,row,col)){
            return true;
        }
       
        
        return false;
        
    }
};