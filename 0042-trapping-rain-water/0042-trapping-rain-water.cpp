class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(100000, 0);
        vector<int> suffix(100000, 0);

        prefix[0] = height[0];
        for(int i = 1;i < height.size();i++){
            prefix[i] = max(prefix[i-1], height[i]); 
        }

        suffix[height.size()-1] = height[height.size()-1];
        for(int i = height.size()-2;i >= 0;i--){
            suffix[i] = max(suffix[i+1], height[i]);
        }

        int ans = 0;
        for(int i = 0;i <= height.size()-1;i++){
            int t = min(prefix[i], suffix[i]) - height[i];
            ans += t;
        }

        return ans;
    }
};