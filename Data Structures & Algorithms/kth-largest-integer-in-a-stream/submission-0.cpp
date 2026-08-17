class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> min_heap;
    int k_limit;
public:
    KthLargest(int k, vector<int>& nums) {
        k_limit=k;
        for(int num:nums){
            add(num);
        }
    }
    
    int add(int val) {
        if(min_heap.size()<k_limit) min_heap.push(val);
        else if(val>=min_heap.top()){
            min_heap.pop();
            min_heap.push(val);
        }
        return min_heap.top();
    }
};
