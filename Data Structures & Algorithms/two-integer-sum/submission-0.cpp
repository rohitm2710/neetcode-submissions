class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> record;
        for(int i=0;i<nums.size();i++){
            int comp=target-nums[i];
            if(record.find(comp)!=record.end()){
                return {record[comp],i};
            }
            record[nums[i]]=i;
        }
        return {};
    }
};
