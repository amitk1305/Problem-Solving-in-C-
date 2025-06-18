class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result(n / 3, vector<int>(3));
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i += 3) {
            if (nums[i + 2] - nums[i] <= k) {
                result[i / 3][0] = nums[i];
                result[i / 3][1] = nums[i + 1];
                result[i / 3][2] = nums[i + 2];
            } else {
                return {};
            }
        }
        return result;
    }
};