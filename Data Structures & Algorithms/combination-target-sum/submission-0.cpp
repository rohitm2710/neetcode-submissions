class Solution {
private:
    vector<vector<int>> res;
    void comb(vector<int>& nums,int target,int k, vector<int>& curr, int curr_sum){
        for(;k<nums.size();k++){
            curr.push_back(nums[k]);
            curr_sum+=nums[k];
            if(curr_sum==target){
                res.push_back(curr);
            }
            else if(curr_sum<target){
                comb(nums,target,k,curr,curr_sum);
            }
            curr.pop_back();
            curr_sum-=nums[k];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        comb(nums,target,0,curr,0);
        return res;
    }
};
