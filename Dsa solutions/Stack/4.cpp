// 921. Minimum Add to Make Parentheses Valid

int minAddToMakeValid(string s) {
    stack<int> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (st.size() != 0 && s[st.top()] == '(' && s[i] == ')')
            st.pop();
        else
            st.push(i);
    }

    return st.size();
    }