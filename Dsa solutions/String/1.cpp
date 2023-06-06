// 647. Palindromic Substrings

bool isPlaindrome(string str){
    int i = 0, j = str.length() - 1;
    while (i < j){
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}
    int countSubstrings(string s){
        int count = 0;
        for(int i = 0;i<s.length();i++){
            for(int j=i;j<s.length();j++){
                string str = s.substr(i, j - i + 1);
                if (isPlaindrome(str))
                    count++;
            }
        }
        return count;
    }