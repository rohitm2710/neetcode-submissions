class Solution {
private:
    vector<vector<char>> dict = {
            {}, // 0
            {}, // 1
            {'a', 'b', 'c'},      // 2
            {'d', 'e', 'f'},      // 3
            {'g', 'h', 'i'},      // 4
            {'j', 'k', 'l'},      // 5
            {'m', 'n', 'o'},      // 6
            {'p', 'q', 'r', 's'}, // 7
            {'t', 'u', 'v'},      // 8
            {'w', 'x', 'y', 'z'}  // 9
        };
        vector<string> res;
        void backtrack(string nums,int i,string curr){
            if(i==nums.size()){
                res.push_back(curr);
                return;
            }
            int n=nums[i]-'0';
            for(char c:dict[n]){
                curr+=c;
                backtrack(nums,i+1,curr);
                curr.pop_back();
            }
        }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string curr;
        backtrack(digits,0,curr);
        return res;
    }
};
