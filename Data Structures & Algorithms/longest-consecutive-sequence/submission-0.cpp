class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int n:nums){
            set.insert(n);
        }
        int maxn=0;
        for(int n:nums){
            if(set.find(n-1)==set.end()){
                int currentNum=n;
                int curr=1;
                while(set.find(currentNum+1)!=set.end()){
                    curr++;
                    currentNum++;
                }
                maxn=max(maxn,curr);
            }
        }
        return maxn;
    }
};
