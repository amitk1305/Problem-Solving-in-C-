class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        for(int j=0;j<nums.size();j++) if(nums[j] == key) for(int i=max({0,j-k, ans.empty() ? 0 : (ans.back()+1)}); i<=min((int)nums.size()-1, j+k);i++) ans.push_back(i);
        return ans;
    }
};