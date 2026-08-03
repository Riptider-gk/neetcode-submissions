class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(); int m=heights[0].size();
        vector<vector<bool>> pvis(n, vector<bool>(m,false));
        vector<vector<bool>> avis(n, vector<bool>(m,false));
        vector<vector<bool>> vis(n, vector<bool>(m,false));
        queue<pair<int,int>> qp;
        queue<pair<int,int>> qa;
        for(int i=0; i<m; i++) {
            pvis[0][i]=true;
            avis[n-1][i]=true;
            qp.push({0,i});
            qa.push({n-1,i});
        }
        for(int i=0; i<n; i++) {
            pvis[i][0]=true;
            avis[i][m-1]=true;
            qp.push({i,0});
            qa.push({i,m-1});
        }
        
        int nrow; int ncol;int row; int col;
        
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        while(!qp.empty()){
            row=qp.front().first; col=qp.front().second; qp.pop();
            int val=heights[row][col];
            vis[row][col]=true;
            for(int i=0; i<4; i++){
                nrow=row+drow[i];
                ncol=col+dcol[i];
                if(ncol>=0&&nrow>=0&&ncol<m&&nrow<n&&vis[nrow][ncol]==false&&val<=heights[nrow][ncol]){
                    qp.push({nrow,ncol});
                    pvis[nrow][ncol]=true;
                }
            }
            
        }

        for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    vis[i][j]=false;
                }
            }
        
        
        while(!qa.empty()){
            row=qa.front().first; col=qa.front().second; qa.pop();
            vis[row][col]=true;
            
            int val=heights[row][col];
            for(int i=0; i<4; i++){
                nrow=row+drow[i];
                ncol=col+dcol[i];
                if(ncol>=0&&nrow>=0&&ncol<m&&nrow<n&&vis[nrow][ncol]==false&&val<=heights[nrow][ncol]){
                    qa.push({nrow,ncol});
                    avis[nrow][ncol]=true;
                }
            }
            
        }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pvis[i][j]&&avis[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
