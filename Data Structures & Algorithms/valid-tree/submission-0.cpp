class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n) return false;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        stack<pair<int,int>> st; //node, parent
        st.push({0,0});
        int node, par;
        while(!st.empty()){
            node=st.top().first; par=st.top().second;
            st.pop();
            if(node!=par&&vis[node]==true) return false;
            vis[node]=true;
            for(int nbr: adj[node]){
                if(nbr==par) continue;
                if(vis[nbr]==true) return false;
                st.push({nbr, node});
            }
        }
        for(bool b: vis){
            if(b==false) return false;
        }
        return true;
    }
};
