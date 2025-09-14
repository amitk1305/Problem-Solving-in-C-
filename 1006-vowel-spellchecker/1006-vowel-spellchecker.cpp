class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {

        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        auto toLower = [](string s) {
            for (char& c : s)
                c = tolower(c);
            return s;
        };

        auto mask = [&](string s) {
            s = toLower(s);
            for (char& c : s) {
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    c = '*';
            }
            return s;
        };

        for (string w : wordlist) {
            string low = toLower(w);
            string msk = mask(w);
            if (!caseInsensitive.count(low))
                caseInsensitive[low] = w;
            if (!vowelInsensitive.count(msk))
                vowelInsensitive[msk] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) { 
                ans.push_back(q);
            } else {
                string low = toLower(q);
                string msk = mask(q);
                if (caseInsensitive.count(low)) {
                    ans.push_back(caseInsensitive[low]);
                } else if (vowelInsensitive.count(msk)) {
                    ans.push_back(vowelInsensitive[msk]);
                } else {
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};