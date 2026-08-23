class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // BFS from each grid[i][j]=0;
        queue<pair<int,int>> q;
        vector<pair<int,int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto loc=q.front();
            q.pop();
            for(auto dir:directions){
                int nr=loc.first+dir.first;
                int nc=loc.second+dir.second;

                if(nr<0||nr==m||nc<0||nc==n||grid[nr][nc]!=INT_MAX){
                    continue;
                }
                grid[nr][nc]=1+grid[loc.first][loc.second];
                q.push({nr,nc});
            }
        }
    }
};
