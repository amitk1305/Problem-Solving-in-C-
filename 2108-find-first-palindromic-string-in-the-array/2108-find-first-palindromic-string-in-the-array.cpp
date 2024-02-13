class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (string t : words) {
            string reversed = t;
            reverse(reversed.begin(), reversed.end());
            
            if (t == reversed) {
                return t;
            }
        }
        return "";
    }
};