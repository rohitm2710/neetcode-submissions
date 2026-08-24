class Solution {
private:
    bool dfs(int node,int parent,vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[node]) return true;
        visited[node]=true;
        for(int nei:adj[node]){
            if(nei==parent) continue;
            if(dfs(nei,node,adj,visited)) return true;
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<bool> visited(n+1);
        vector<vector<int>> adj(n+1);
        for(const auto& edge :edges){
            int u=edge[0],v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            fill(visited.begin(),visited.end(),false);
            if(dfs(u,-1,adj,visited)){
                return {u,v};
            }
        }
        return {};
    }
};
