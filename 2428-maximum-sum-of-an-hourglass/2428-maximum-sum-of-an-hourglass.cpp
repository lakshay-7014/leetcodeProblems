class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int row= grid.size();
        int col=grid[0].size();
        int sum=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i<row-2 && j<col-2){
                  int val = grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j] +grid[i+2][j+1]+grid[i+2][j+2];
                    sum=max(sum,val);
                }
            }
        }
        return sum;
    }
};