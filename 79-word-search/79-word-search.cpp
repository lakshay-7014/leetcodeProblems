class Solution {
    private:
    bool solve(vector<vector<char>>& board, vector<vector<int>> &visited,int x,int y,string &word,int index){
        int row=board.size();
        int col=board[0].size();
       if(index==word.length()-1){
           return true;
       }
        visited[x][y]=1;  
        //up
        int newx=x-1;
        int newy=y;
       if(newx >=0 && newx<row && visited[newx][newy]==0 && board[newx][newy]==word[index+1] && solve(board,visited,newx,newy,word,index+1)){
           return true;
       }
       
        
        //down
        newx=x+1;
        newy=y;
        if(newx<row && visited[newx][newy]==0 && board[newx][newy]==word[index+1] && solve(board,visited,newx,newy,word,index+1)){
           return true;
       }
        
        //left
        newx=x;
        newy=y-1;
        if(newy >=0 && visited[newx][newy]==0 && board[newx][newy]==word[index+1] && solve(board,visited,newx,newy,word,index+1)){
           return true;
       }
         
        
        //right
        newx=x;
        newy=y+1;
          if(newy<col  && visited[newx][newy]==0 && board[newx][newy]==word[index+1] && solve(board,visited,newx,newy,word,index+1)){
           return true;
       }
            
        visited[x][y]=0;
        return false ;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
         int row=board.size();
        int col=board[0].size();
        
        vector<vector<int>> visited(row,vector<int>(col,0));
        int index=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0] && solve(board,visited,i,j,word,index)){
                    return true;
                }
            }
        }
      
        return false;
    }
};