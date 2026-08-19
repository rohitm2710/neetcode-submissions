class Solution {
private:
    void dfs(vector<vector<int>>& grid,int i,int j,int& curr){
        if(i<0||j<0||i==grid.size()||j==grid[0].size()||grid[i][j]==0) return;
        grid[i][j]=0;
        curr++;
        dfs(grid,i+1,j,curr);
        dfs(grid,i,j+1,curr);
        dfs(grid,i-1,j,curr);
        dfs(grid,i,j-1,curr);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_val=0;
        int curr=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    dfs(grid,i,j,curr);
                    max_val=max(max_val,curr);
                    curr=0;
                }
            }
        }
        return max_val;
    }
};
