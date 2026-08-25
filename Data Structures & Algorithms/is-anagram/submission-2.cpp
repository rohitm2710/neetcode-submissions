class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> bucket(26,0);
        for(char c:s){
            bucket[c-'a']++;
        }
        for(char c:t){
            bucket[c-'a']--;
        }
        for(int i=0;i<26;i++){
            if(bucket[i]!=0){
                return false;
            }
        }
        return true;
    }
};
