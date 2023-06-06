// 20. Valid Parentheses

bool isValid(string s) {
    stack<int> st;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            st.push(i);
        else
        {
            if (st.size() == 0)
                return false;
            else if (s[i] == ')' && s[st.top()] != '(')
                return false;
            else if (s[i] == ']' && s[st.top()] != '[')
                return false;
            else if (s[i] == '}' && s[st.top()] != '{')
                return false;
            else
                st.pop();
        }
    }

    return st.size() == 0;
    }