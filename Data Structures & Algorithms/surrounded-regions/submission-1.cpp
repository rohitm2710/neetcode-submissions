class Solution {
private:
    int m;
    int n;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0||i==m||j<0||j==n||grid[i][j]=='X'||grid[i][j]=='s') return;
        grid[i][j]='s';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
    }
public:
    void solve(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0||i==m-1||j==0||j==n-1){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            dfs(grid,r,c);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
                else if(grid[i][j]=='s'){
                    grid[i][j]='O';
                }
            }
        }
    }
};
