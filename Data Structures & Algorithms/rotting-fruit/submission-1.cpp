class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(); int m=grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
            }
        } int tm=0, t=0; int nrow, ncol;
        int drow[4]={-1,0,1,0}; int dcol[4]={0,-1,0,1};
        
        while(!q.empty()){
            t=q.front().second;
            tm=max(t,tm);
            int r=q.front().first.first; int c=q.front().first.second;
            q.pop();
            for(int i=0; i<4; i++){
                nrow=r+drow[i];
                ncol=c+dcol[i];
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&grid[nrow][ncol]==1&&vis[nrow][ncol]==0){
                    vis[nrow][ncol]=2;
                    
                    q.push({{nrow,ncol},t+1});
                }
            }
           
           } 
           for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]!=2&&grid[i][j]==1) return -1;
            }
        }
        return tm;
    }
};
