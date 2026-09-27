class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        for(auto c:s){
            if(c=='('){
                st.push(c);
            }else if(c==')'){
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(auto ch:temp){
                    st.push(ch);
                }
            }else{
                st.push(c);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};