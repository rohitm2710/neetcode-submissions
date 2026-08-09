class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> min_heap;
        for(vector<int>& interval : intervals){
            min_heap.push(interval);
        }
        vector<vector<int>> res;
        res.push_back(min_heap.top());
        min_heap.pop();
        while(!min_heap.empty()){
            auto curr=min_heap.top();
            min_heap.pop();
            if(curr[0]<=res.back()[1]){
                res.back()={res.back()[0],max(curr[1],res.back()[1])};
            }
            else{
                res.push_back(curr);
            }
        }
        return res;
    }
};
