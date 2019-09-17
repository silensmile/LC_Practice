#include<stack>
#include<string>
using std::stack;
using std::string;

bool isValid(string s) {
    if (s.empty())
        return true;
    if (s[0] == ')' || s[0] == ']' || s[0] == '}')
        return false;
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
            continue;
        }
        else if (!st.empty()) {
            if (s[i] == ')'&&st.top() == '(' || s[i] == ']'&&st.top() == '[' || s[i] == '}'&&st.top() == '{')
                st.pop();
            else
                return false;
        }
        else
            return false;
    }
    if (st.empty())
        return true;
    else
        return false;
}

void isValidTest() {
    string s = "()[]{}";
    bool a = isValid(s);
}