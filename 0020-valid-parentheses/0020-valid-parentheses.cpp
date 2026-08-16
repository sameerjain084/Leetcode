class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (int i = 0; i < str.size(); i++) {

            // Opening brackets
            if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
                st.push(str[i]);
            }
            else {
                // No opening bracket available
                if (st.size() == 0) {
                    return false;
                }

                // Check matching bracket
                if ((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};