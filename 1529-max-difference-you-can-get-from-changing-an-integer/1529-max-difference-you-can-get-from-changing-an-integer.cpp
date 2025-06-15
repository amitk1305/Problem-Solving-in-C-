class Solution {
public:
    int maxDiff(int num) {
        // Convert the number to string for easy digit manipulation
        string s = to_string(num);
        string s2 = s;  // Copy of original string to create maximum number
        char ch = s[0]; // Store the first digit

        int n = s.size();

        // ------------ Create the minimum number ----------------
        if (s[0] == '1') {
            // Case 1: If the number starts with 1
            // Find the first digit which is not '1' or '0' (can't replace with '0' if it's first digit)
            bool flag = false;
            for (int i = 0; i < n; i++) {
                if (s[i] != '1' && s[i] != '0') {
                    ch = s[i]; // We will replace this digit with '0'
                    flag = true;
                    break;
                }
            }
            // Replace all occurrences of ch with '0'
            for (int i = 0; i < n; i++) {
                if (s[i] == ch && flag) {
                    s[i] = '0';
                }
            }
        } else {
            // Case 2: If the number doesn't start with 1 (e.g. starts with 2,3,...)
            // Replace all occurrences of the first digit with '1'
            for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    s[i] = '1';
                }
            }
        }

        // Convert the modified string to integer
        int mini = stoi(s);

        // ------------ Create the maximum number ----------------
        char ch2 = s2[0];

        // Find the first digit that is not '9' to replace with '9'
        for (int i = 0; i < n; i++) {
            if (s2[i] != '9') {
                ch2 = s2[i]; // This is the digit we will replace with '9'
                break;
            }
        }

        // Replace all occurrences of ch2 with '9'
        for (int i = 0; i < n; i++) {
            if (s2[i] == ch2) {
                s2[i] = '9';
            }
        }

        // Convert the modified string to integer
        int maxi = stoi(s2);

        // Return the maximum difference
        return maxi - mini;
    }
};