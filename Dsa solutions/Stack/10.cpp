// 1081. Smallest Subsequence of Distinct Characters

string smallestSubsequence(string s)
{
    if (s.length() <= 1)
        return s;

    vector<bool> seen(26, false);
    vector<int> freq(26, 0);

    for (char ch : s)
        freq[ch - 'a']++;

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        freq[ch - 'a']--;
        if (seen[ch - 'a'])
            continue;

        while (st.size() != 0 && st.top() > ch && freq[st.top() - 'a'] > 0)
        {
            seen[st.top() - 'a'] = false;
            st.pop();
        }

        seen[ch - 'a'] = true;
        st.push(ch);
    }

    string ans = "";
    while (st.size() != 0)
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// 316. Remove Duplicate Letters

string removeDuplicateLetters(string s) {
        if (s.length() <= 1)
        return s;

    vector<bool> seen(26, false);
    vector<int> freq(26, 0);

    for (char ch : s)
        freq[ch - 'a']++;

    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];

        freq[ch - 'a']--;
        if (seen[ch - 'a'])
            continue;

        while (st.size() != 0 && st.top() > ch && freq[st.top() - 'a'] > 0)
        {
            seen[st.top() - 'a'] = false;
            st.pop();
        }

        seen[ch - 'a'] = true;
        st.push(ch);
    }

    string ans = "";
    while (st.size() != 0)
    {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}