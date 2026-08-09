class Solution {
private:
    unordered_set<int> seen;
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(vector<int>& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        queue<pair<int,int>> q;
        q.push({0,-1});
        seen.insert(0);
        while(!q.empty()){
            auto [node,parent]=q.front();
            q.pop();
            for(int neighbor : adj[node]){
                if(neighbor==parent) continue;
                if(seen.count(neighbor)) return false;

                seen.insert(neighbor);
                q.push({neighbor,node});
            }
        }
        return seen.size()==n;
    }
};
