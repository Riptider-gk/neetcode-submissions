class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<bool>> visit;
    int row, col;

    int dfs(int i, int j){
        if(i<0 || j<0 || i>=row || j>= col || grid[i][j]==0) return 1;
        else if (visit[i][j]==true) return 0;
        visit[i][j]=true;
        return dfs(i,j-1) + dfs(i,j+1) + dfs(i-1,j)+dfs(i+1,j);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        this->grid=grid;
        row=grid.size();
        col=grid[0].size();
        visit=vector<vector<bool>>(row, vector<bool>(col,false));

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    return dfs(i,j);
                }
            }
        }
        return 0;
    }
};