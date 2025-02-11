class Solution {
public:
    string removeOccurrences(string a, string part) {
        while (a.find(part) != string::npos) {  // Keep removing until part is no longer found
            a.erase(a.find(part), part.size()); 
        }
        return a;
    }
};