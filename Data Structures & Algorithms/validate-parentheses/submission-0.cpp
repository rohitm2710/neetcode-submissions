class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2!=0) return false;
        stack<char> st;
        for(int i=s.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(s[i]=='(' && st.top()==')'){
                st.pop();
            }
            else if(s[i]=='{' && st.top()=='}'){
                st.pop();
            }
            else if(s[i]=='[' && st.top()==']'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};
