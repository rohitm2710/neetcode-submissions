class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        if(s==t) return s;
        unordered_map<char,int> countT;
        unordered_map<char,int> window;
        for(int i=0;i<t.size();i++){
            countT[t[i]]++;
            window[t[i]]=0;
        }
        int need=countT.size();
        int have=0;
        int last=0;
        while(last<s.size() && window.find(s[last])==window.end()){
            last++;
        }
        if(last==s.size()) return "";
        int i=last;
        int min_last;
        int min_len=INT_MAX;
        for(;i<s.size();i++){
            char c=s[i];
            window[c]++;
            if(countT.count(c)&&window[c]==countT[c]){
                have++;
            }

            while(have==need){
                if(i-last+1<min_len){
                    min_len=i-last+1;
                    min_last=last;
                }
                window[s[last]]--;
                if(countT.count(s[last])&&window[s[last]]<countT[s[last]]){
                    have--;
                }
                last++;
            }
        }
        if(min_len==INT_MAX){
            return "";
        }
        return s.substr(min_last,min_len);
    }
};
