class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stone_heap;
        for(int stone:stones){
            stone_heap.push(stone);
        }
        while(stone_heap.size()>1){
            int x=stone_heap.top();
            stone_heap.pop();
            int y=stone_heap.top();
            stone_heap.pop();
            if(x!=y){
                stone_heap.push(abs(x-y));
            }
        }
        if(stone_heap.empty()) return 0;
        return stone_heap.top();
    }
};
