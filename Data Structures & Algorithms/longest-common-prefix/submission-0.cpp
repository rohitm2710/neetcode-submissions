class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s;
        bool done=false;
        for(int i=0;i<strs[0].size();i++){
            for(int j=1;j<strs.size();j++){
                if(i==strs[j].size()||strs[0][i]!=strs[j][i]){
                    done=true;
                    break;
                }
            }
            if(done) break;
            s+=strs[0][i];
        }
        return s;
    }
};