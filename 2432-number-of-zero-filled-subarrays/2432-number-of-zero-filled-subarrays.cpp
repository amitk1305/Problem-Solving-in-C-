class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long counter = 0, total = 0;
        for (int num : nums) {
            if (num == 0) {
                counter++;
                total += counter;
            } else {
                counter = 0;
            }
        }
        return total;
    }
};