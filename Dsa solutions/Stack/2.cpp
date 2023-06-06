//1021. Remove Outermost Parentheses

string removeOuterParentheses(string s) {
        string str = "";

    int balanceBrac = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' && balanceBrac++ > 0)
            str += s[i];
        else if (s[i] == ')' && balanceBrac-- > 1)
            str += s[i];
    }

    return str;
    }