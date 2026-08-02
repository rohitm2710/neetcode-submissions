class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> min_heap;
        unordered_map<int,int> bucket;
        for(int n:nums){
            bucket[n]++;
        }
        for(const auto& [key,value]:bucket){
            min_heap.push({value,key});
        }
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return res;
    }
};
