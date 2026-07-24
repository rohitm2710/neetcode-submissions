class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])==map.end()){
                map[nums[i]]=i;
            }
            else    return true;
        }
        return false;
    }
};