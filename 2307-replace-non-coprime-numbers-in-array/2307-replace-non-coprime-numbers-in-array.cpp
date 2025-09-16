class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n = nums.size();
        int i = 1;
        vector<int> ans;
        ans.push_back(nums[0]);
        
        while (i < n) {
            // keep merging while last element and nums[i] are non-coprime
            while (i < n && __gcd(ans.back(), nums[i]) != 1) {
                ans.back() = ans.back() * (nums[i] / __gcd(ans.back(), nums[i]));
                i++;
                // check backwards for possible new merges
                while (ans.size() > 1 && __gcd(ans.back(), ans[ans.size()-2]) > 1) {
                    int val = ans.back();
                    ans.pop_back();
                    ans.back() = ans.back() * (val / __gcd(val, ans.back()));
                }
            }
            if (i >= n) break;
            ans.push_back(nums[i]);
            i++;
        }
        return ans;
    }
};
