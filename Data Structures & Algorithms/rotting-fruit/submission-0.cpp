class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>> q;
        int fresh=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
        int time=0;
        int qSize=q.size();
        while(!q.empty()&&fresh>0){
            for(int i=0;i<qSize;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(auto dir:directions){
                    int nr=r+dir.first;
                    int nc=c+dir.second;
                    if(nr<0||nr==m||nc<0||nc==n||grid[nr][nc]==0||grid[nr][nc]==2){
                        continue;
                    }
                    grid[nr][nc]=2;
                    fresh--;
                    q.push({nr,nc});
                }
            }
            time++;
            if(!q.empty()){
                qSize=q.size();
            }
        }
        if(fresh>0) return -1;
        return time;
    }
};
