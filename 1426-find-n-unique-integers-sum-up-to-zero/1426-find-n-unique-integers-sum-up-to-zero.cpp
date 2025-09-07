class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        for (int i = 1, sum = 0; i <= n; i++) {
            if (i < n) {
                result.push_back(i);
                sum += i;
            } else {
                result.push_back(-sum);
            }
        }
        return result;
    }
};