// Solution 2:
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int rem = s.size() % k;
        if (rem) s.append(k - rem, fill);
        vector<string> res;
        res.reserve(s.size() / k);
        for (int i = 0; i < (int)s.size(); i += k)
            res.emplace_back(s.substr(i, k));
        return res;
    }
};

// Solution 1:
// class Solution {
// public:
//     vector<string> divideString(string s, int k, char fill) {
//         vector<string> res;
//         int n = s.size();
//         for (int i = 0; i < n; i += k) {
//             string t = s.substr(i, k);
//             if ((int)t.size() < k) t += string(k - t.size(), fill);
//             res.push_back(t);
//         }
//         return res;
//     }
// };