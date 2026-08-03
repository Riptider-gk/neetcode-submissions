class Solution {
    private:
    int ans=0; int curr=0;
    vector<vector<int>> grid;
    int row,col;
    vector<vector<bool>> vis;
    int dfs(int i, int j){
        if(i<0||j<0||row-1<i||col-1<j||grid[i][j]==0) return 1;
        if(vis[i][j]) return 0;
        curr++;
        vis[i][j]=true;
        return dfs(i+1,j)+dfs(i-1,j)+dfs(i,j+1)+dfs(i,j-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid=grid;
        
         int mx;
        row=grid.size(); col=grid[0].size();
        vis=vector<vector<bool>>(row, vector<bool>(col,false));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]&&!vis[i][j]){
                    mx=dfs(i,j);
                    ans=max(curr,ans);
                    curr=0;
                }
            }
        }
        return ans;
    }
};
