class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int max_ele=*max_element(nums.begin(), nums.end());

        int cnt=0;
        int max_len=0;
        int n=nums.size();

        for(int i=0;i<n; i++){
          if(nums[i]==max_ele) cnt++;
          else cnt=0;

          max_len=max(max_len, cnt);
        }

        return max_len;
    }
};