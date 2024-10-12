#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> freqCount;
        int n = nums.size();

        // Count frequency of each integer across all subarrays
        for (const auto& array : nums) {
            for (int num : array) {
                freqCount[num]++;
            }
        }

        vector<int> result;

        // Collect integers that appear in all arrays
        for (const auto& [num, count] : freqCount) {
            if (count == n) {
                result.push_back(num);
            }
        }

        // Sort the result in ascending order
        sort(result.begin(), result.end());

        return result;
    }
};
