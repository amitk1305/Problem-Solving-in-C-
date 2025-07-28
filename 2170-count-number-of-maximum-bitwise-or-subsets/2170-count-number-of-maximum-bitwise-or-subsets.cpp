class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int target = 0;
        for (int num : nums) {
            target |= num;
        }
        return backtrack(nums, 0, 0, target);
    }
    
private:
    int backtrack(vector<int>& nums, int index, int current, int target) {
        if (index == nums.size()) {
            return current == target ? 1 : 0;
        }
        return backtrack(nums, index + 1, current, target) + 
               backtrack(nums, index + 1, current | nums[index], target);
    }
};