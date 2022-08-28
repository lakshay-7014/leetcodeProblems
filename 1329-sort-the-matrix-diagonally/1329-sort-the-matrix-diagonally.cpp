class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>> ans(row,vector<int>(col,0));
        int x1=0;
        int y1=col-1;
        
        while(y1>=0){
            int x=x1;
            int y=y1;
            vector<int> temp;
            while(x <row && y<col){
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x=x1;
            y=y1;
            int index=0;
            while(x <row && y<col){
                ans[x][y]=temp[index];
                index++;
                x++;
                y++;
            }
            temp.clear();
            y1--;
        }
        int x2=row-1;
        int y2=0;
         while(x2>0){
            int x=x2;
            int y=y2;
            vector<int> temp;
            while(x <row && y<col){
                temp.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(temp.begin(),temp.end());
            x=x2;
            y=y2;
            int index=0;
            while(x <row && y<col){
                ans[x][y]=temp[index];
                index++;
                x++;
                y++;
            }
            temp.clear();
            x2--;
        }
        
        return ans;
        
    
    }
};