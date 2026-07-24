class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq_s;
        unordered_map<char,int> freq_t;
        for(char c:s){
            if(freq_s.find(c)==freq_s.end()){
                freq_s[c]=1;
            }
            else{
                freq_s[c]++;
            }
        }
        for(char c:t){
            if(freq_t.find(c)==freq_t.end()){
                freq_t[c]=1;
            }
            else{
                freq_t[c]++;
            }
        }
        return freq_s==freq_t;
    }
};
