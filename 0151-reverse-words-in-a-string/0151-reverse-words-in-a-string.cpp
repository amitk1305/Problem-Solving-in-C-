class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0;
        int r = 0;
        int i = 0;
        int n = s.size();
        while(i<n)
        {
            // Skip all the spaces
            while(i < n && s[i] == ' ') i++;
            // Scan the word
            while(i < n && s[i] != ' ') s[r++] = s[i++];

            if(l < r)
            {
                reverse(s.begin() + l, s.begin() + r);
                // Add one space between words
                s[r++] = ' ';
                l = r;
            }
            i++;
        }
        if(r>0) s.resize(r-1);
        return s;
    }
};