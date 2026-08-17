class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k>nums.size()) return {};
        vector<int> res;
        priority_queue<pair<int,int>> heap;
        for(int i=0;i<k;i++){
            heap.push({nums[i],i});
        }
        res.push_back(heap.top().first);
        int l=0;
        int r=k-1;
        while(r<nums.size()-1){
            l++;
            r++;
            heap.push({nums[r],r});
            while(heap.top().second<l){
                heap.pop();
            }
            res.push_back(heap.top().first);
        }
        return res;
    }
};
