// 541 Reverse String II

void reverseRange(string &s, int i, int j){
    while (i < j)
    {
        swap(s[i++], s[j--]);
    }
}

string reverseStr(string s, int k) {
        if (k == 0 || k == 1 || s.length() <= 1)
        return s;

    int i = 0, n = s.length();

    while (i < n)
    {
        if (i + k - 1 < n)
        {
            reverseRange(s, i, i + k - 1);
            i += 2 * k;
        }
        else
        {
            reverseRange(s, i, n - 1);
            break;
        }
    }
    return s;
    }