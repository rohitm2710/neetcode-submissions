class Solution {
private:
    vector<vector<int>> res;
    vector<int> curr;
    vector<int> used;
    void backtrack(vector<int>& nums){
        if(curr.size()==nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=1;
            curr.push_back(nums[i]);
            backtrack(nums);
            used[i]=0;
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(),0);
        backtrack(nums);
        return res;
    }
};
