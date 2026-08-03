class Solution {
    private:
    vector<vector<char>> grid;
    vector<vector<bool>> visited;
    
    int rows,cols;

    void dfs(int i, int j){
        if(i<0||j<0||rows-1<i||cols-1<j) return;
        if(visited[i][j]) return;
        if(grid[i][j]=='0') return;
        visited[i][j]=1;
        dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i, j-1);
    }
    public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
       this->grid=grid; 
       cols=grid[0].size(); rows=grid.size();
       visited= vector<vector<bool>>(rows, vector<bool>(cols, false)); 
       for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(grid[i][j]=='1'&&!visited[i][j]) {dfs(i, j); ans++;}
        }
       } 
       return ans;
    }
};
