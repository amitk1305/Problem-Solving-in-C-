#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        bool allEqualK = true;
        for (int num : nums) {
            if (num != k) {
                allEqualK = false;
                break;
            }
        }
        if (allEqualK) return 0;

        unordered_set<int> s;
        for (int num : nums) {
            if (num > k) {
                s.insert(num);
            }
        }

        int minVal = *min_element(nums.begin(), nums.end());
        if (!s.empty() && minVal >= k) {
            return s.size();
        }

        return -1;
    }
};