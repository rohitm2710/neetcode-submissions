class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int acc_xor=0;
        int num_xor=nums[0];
        for(int i=1;i<=nums.size();i++){
            acc_xor^=i;
        }
        for(int i=1;i<nums.size();i++){
            num_xor^=nums[i];
        }
        return acc_xor^num_xor;
    }
};
