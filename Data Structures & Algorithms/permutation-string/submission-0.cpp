class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> buckets1(26,0);
        vector<int> buckets2(26,0);
        for(char c : s1){
            buckets1[c-'a']++;
        }
        int l=0;
        int r=s1.size()-1;
        for(int i=0;i<s1.size();i++){
            buckets2[s2[i]-'a']++;
        }
        if(buckets1==buckets2) return true;
        while(r<s2.size()-1){
            buckets2[s2[l]-'a']--;
            l++;
            r++;
            buckets2[s2[r]-'a']++;
            if(buckets1==buckets2) return true;
        }
        return false;
    }
};
