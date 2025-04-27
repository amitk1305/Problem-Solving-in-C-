class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0, n = nums.size();
        for (int i = 1; i + 1 < n; ++i)
            count += (nums[i] % 2 == 0 && nums[i] / 2 == nums[i - 1] + nums[i + 1]);
        return count;
    }
};