class Solution {
public:
    int findMin(vector<int> &nums) {
        int minn=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<minn){
                minn=nums[i];
                break;
            }
        }
        return minn;
    }
};
