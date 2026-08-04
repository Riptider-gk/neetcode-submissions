class Solution {
    private:
    vector<int> visit;

    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& path){
        
        path[node]=true;
        vis[node]=true;
        for(int nbr: adj[node]){
            if(!vis[nbr]){
                if(dfs(nbr, adj, vis, path)) return true;
            }
            else if(path[nbr]) return true;
        }
        path[node]=false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(numCourses, 0);
        vector<int> path(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, path)) return false;
            }
        }
        return true;
    }
};
