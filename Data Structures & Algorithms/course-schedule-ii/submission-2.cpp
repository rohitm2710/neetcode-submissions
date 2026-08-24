class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        vector<int> res;
        for(auto& pre:prerequisites){
            int course=pre[0];
            int prereq=pre[1];
            adj[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int course=q.front();
            q.pop();
            for(auto next:adj[course]){
                inDegree[next]--;
                if(inDegree[next]==0){
                    q.push(next);
                    res.push_back(next);
                }
            }
        }
        if(res.size()==numCourses){
            return res;
        }
        return {};
    }
};
