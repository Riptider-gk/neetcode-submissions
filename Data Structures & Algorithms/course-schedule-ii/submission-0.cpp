class Solution {
    private:
    int n;
    vector<int> ans;
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& path, int num){
        vis[node]=true;
        path[node]=1;
        for(int nbr: adj[node]){
            if(!vis[nbr]){
                if(dfs(nbr, adj, vis, path, num)) return true; //cycle detected
            }
            else if (path[nbr]!=-1) return true; //cycle detected
            
        }
        
        
        ans.push_back(node);
        path[node]=-1;
        return false; //not the entire path yet
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<int> path(numCourses, -1);
        vector<vector<int>> adj(numCourses);
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        int num=0;
        for(int i=0; i<numCourses; i++){
            
            n=0;
            if(!vis[i]&& dfs(i, adj, vis, path, numCourses)) 
            return {};
        }
        
        
        return ans;
    }
};
