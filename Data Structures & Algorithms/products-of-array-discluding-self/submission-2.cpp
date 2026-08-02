class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long multiply=1;
        int zero_count=0;
        bool have_digit=false;
        for(int n:nums){
            if(n==0){
                zero_count++;
            }
            if(n!=0){
                have_digit=true;
                multiply*=n;
            }
        }
        vector<int> res(nums.size(),0);
        if(!have_digit) return res;
        if(zero_count == 0){
            for(int i=0;i<nums.size();i++){
                res[i]=multiply/nums[i];
            }
        }
        else if(zero_count == 1){
            for(int i=0;i<nums.size();i++){
                if(nums[i]!=0){
                    res[i]=0;
                }
                else{
                    res[i]=multiply;
                }
            }
        }
        else{
            // If there is more than one zero, all products are 0
            return res;
        }
        return res;
    }
};