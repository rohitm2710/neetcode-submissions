class Solution {
private:
    void dfs(int i,vector<vector<int>>& adj,vector<bool>& visited){
        if(visited[i]){
            return;
        }
        visited[i]=true;
        for(int neighbor:adj[i]){
            dfs(neighbor,adj,visited);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(const auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};
