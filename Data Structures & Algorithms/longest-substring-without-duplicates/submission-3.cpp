class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        vector<int> bucket(256,-1);
        int n=s.size();
        if(n==1) return 1;
        int last=0;
        int i;
        for(i=0;i<n;i++){
            if(bucket[s[i]]==-1||bucket[s[i]]<last){
                bucket[s[i]]=i;
            }
            else{
                max_len=max(max_len,i-last);
                last=bucket[s[i]]+1;
                bucket[s[i]]=i;
            }
            max_len=max(max_len,i-last+1);
        }
        return max_len;
    }
};
