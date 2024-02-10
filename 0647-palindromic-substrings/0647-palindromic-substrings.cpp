bool isPalindrome(string str) {
    int i = 0, t = str.size() - 1; 
    while (i <= t)if (str[i++] != str[t--])return false;
    return true;
}
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s.substr(i, j - i + 1)))cnt++;
            }
        }
        return cnt;
    }
};