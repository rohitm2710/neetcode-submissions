class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int s1=nums[0];
        int s2=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int res=max(nums[i]+s1,s2);
            s1=s2;
            s2=res;
        }
        return s2;
    }
};
