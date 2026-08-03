class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.size();
        int maxf=0;
        int max_len=0;
        vector<int> count(26,0);
        for(int r=0;r<n;r++){
            count[s[r]-'A']++;
            maxf=max(maxf,count[s[r]-'A']);
            while((r-l+1)-maxf>k){
                count[s[l]-'A']--;
                l++;
            }
            max_len=max(max_len,r-l+1);
        }
        return max_len;
    }
};
