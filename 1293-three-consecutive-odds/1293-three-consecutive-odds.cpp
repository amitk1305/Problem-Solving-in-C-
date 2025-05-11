class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return false;

        for (int i = 1; i < n - 1; i++) {
            int prev = i - 1, curr = i + 1;
            if (arr[i] % 2 == 1 && arr[prev] % 2 == 1 && arr[curr] % 2 == 1) {
                return true;
            }
        }

        return false;
    }
};