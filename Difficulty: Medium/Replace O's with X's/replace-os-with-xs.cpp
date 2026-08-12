class Solution {
    void solve(int i, int j,vector<vector<char>>& mat ){
        int row = mat.size();
        int col = mat[0].size();
    if(i<0||j<0||i>row-1||j>col-1||mat[i][j]=='v'||mat[i][j]=='X') return;
    
    mat[i][j]='v';
    
    solve(i+1,j,mat);
    solve(i,j+1,mat);
    solve(i-1,j,mat);
    solve(i,j-1,mat);
    
    }
    
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        char value;
        int row = grid.size();
        int col = grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
            if(grid[i][j]=='O'&&(i==0||j==0||i==row-1||j==col-1)){
                solve(i,j,grid);
            }
        }
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
            if(grid[i][j]=='v'){
                grid[i][j]='O';
            }
            else if(grid[i][j]=='O'){
                grid[i][j]='X';
            }
        }
        }
        // return grid;
    }
};