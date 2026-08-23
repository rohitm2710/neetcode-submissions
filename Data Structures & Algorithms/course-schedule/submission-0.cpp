class Solution {
private:
    unordered_set<int> seen;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(vector<int>& pre:prerequisites){
            int course=pre[0];
            int precourse=pre[1];
            adj[precourse].push_back(course);
            indegree[course]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int complete=0;
        while(!q.empty()){
            int course=q.front();
            q.pop();
            complete++;
            for(int next:adj[course]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }
        return complete==numCourses;
    }
};
