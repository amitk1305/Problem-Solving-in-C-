class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, max_len = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (nums[right] - nums[left] > 1) {
                ++left;
            }
            if (nums[right] - nums[left] == 1) {
                max_len = max(max_len, right - left + 1);
            }
        }

        return max_len;
    }
};