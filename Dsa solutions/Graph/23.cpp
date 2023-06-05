//1061 Lexicographically smallestEquivalentString

vector<int> par;
int findPar(int u)
{
    return par[u] == u ? u : (par[u] = findPar(par[u]));
}

string smallestEquivalentString(string s1, string s2, string baseStr){
    for (int i = 0; i < 26; i++)
        par.push_back(i);
    for (int i = 0; i < s1.length(); i++)
    {
        char c1 = s1[i], c2 = s2[i];
        int p1 = findPar(c1 - 'a'), p2 = findPar(c2 - 'a');
        par[p1] = min(p1, p2);
        par[p2] = min(p1, p2);
    }

    string ans = "";
    for (char ch : baseStr)
    {
        int p = findPar(ch - 'a');
        ans += (char)(p + 'a');
    }

    return ans;
   }