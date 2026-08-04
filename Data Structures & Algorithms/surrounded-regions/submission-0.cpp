class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        //do dfs from all the boundary o cells (only if o) and unvisited o are the answer
        int n=grid.size(); int m=grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        for(int i=0; i<n; i++){
                if(grid[i][0]=='O') vis[i][0]=true;
                if(grid[i][m-1]=='O') vis[i][m-1]=true;
        }
        for(int j=0; j<m; j++){
            if(grid[0][j]=='O') vis[0][j]=true;
            if(grid[n-1][j]=='O') vis[n-1][j]=true;
        }

        queue<pair<int,int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]) q.push({i,j});
            }
            
        }

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int nrow, ncol, row, col;

        while(!q.empty()){
            row=q.front().first; col=q.front().second;
            q.pop();
            vis[row][col]=true;
            for(int i=0; i<4; i++){
                nrow=row+drow[i];
                ncol=col+dcol[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&!vis[nrow][ncol]&&grid[nrow][ncol]=='O'){
                    q.push({nrow, ncol}); 
                    vis[nrow][ncol]=true;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]) grid[i][j]='X';
            }
            
        }

    }
};
