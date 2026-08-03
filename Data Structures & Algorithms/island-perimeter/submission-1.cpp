class Solution {
    
public:
    int dfs(int n, int m, vector<vector<bool>>& visited,  vector<vector<int>>& grid){
        int row=grid.size(), col=grid[0].size();
        
        if(n>=row||n<0||m<0||m>=col||grid[n][m]==0) return 1;
        if(visited[n][m]) return 0;
        visited[n][m]=1;
        return dfs(n-1,m,visited,grid)+dfs(n+1,m,visited,grid)+
        dfs(n,m+1,visited,grid)+dfs(n,m-1,visited,grid);

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows=grid.size(), cols=grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));  
        int ans=0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]) return dfs(i,j,visited,grid);
            }
        }
        return 0;
    }
};
/*
stack<int> st;
        st.push(src);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(vis[node]) continue;
            vis[node]=1;
            for(int child:adj[node]) st.push(child);
        }
*/