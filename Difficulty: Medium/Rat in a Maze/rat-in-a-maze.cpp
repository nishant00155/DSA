class Solution {
    
  
    void solve(int i,int j,vector<vector<int>>& maze,string path,vector<string>&ans){
        int n = maze.size();
        if(i<0||j<0||i>=n||j>=n||maze[i][j]==0){
            return;
        }
        if(i==n-1&& j==n-1){
            ans.push_back(path);
            return;
        }
        
        maze[i][j]=0;
        
        solve(i+1,j,maze,path+"D",ans);
        solve(i,j+1,maze,path+"R",ans);
        solve(i,j-1,maze,path+"L",ans);
        solve(i-1,j,maze,path+"U",ans);
        
        maze[i][j]=1;
    }
    
    
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code her 
        int n = maze.size();
        vector<string>ans;
        if(maze[0][0]&&maze[n-1][n-1]){
           solve(0,0,maze,"",ans); 
        }
        
        sort(ans.begin(), ans.end());

        
        return ans;
    }
};