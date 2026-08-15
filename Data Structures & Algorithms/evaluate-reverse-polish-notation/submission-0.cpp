class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        st.push(stoi(tokens[0]));
        for(int i=1;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num=st.top();
                st.pop();
                if(tokens[i]=="+"){
                    st.top()+=num;
                }
                else if(tokens[i]=="-"){
                    st.top()-=num;
                }
                else if(tokens[i]=="*"){
                    st.top()*=num;
                }
                else if(tokens[i]=="/"){
                    st.top()/=num;
                }
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
