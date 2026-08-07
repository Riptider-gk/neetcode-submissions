class Solution {
    int comps;
    vector<int> Parent, Size;
public:
    void DSU(int n){
        comps=n;
        Parent.resize(n+1);
        Size.resize(n+1);
        for(int i=0; i<=n; i++){
            Parent[i]=i;
            Size[i]=1;
        }
    }
    int find(int node){
        if(Parent[node]!=node){
            Parent[node]=find(Parent[node]);
        }
        return Parent[node];
    }

    bool unionNodes(int u, int v){
        int pu=find(u), pv=find(v);
        if(pu==pv) return false;
        if(Size[pu]<Size[pv]) swap(pu,pv);
        comps--;
        Size[pu]+=Size[pv];
        Parent[pv]=pu;
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;
        DSU(n);
        for(auto& edge: edges){
            if(!unionNodes(edge[0], edge[1])) return false;
        }
        return (comps==1);
    }
};
