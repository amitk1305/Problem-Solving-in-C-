class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<std::map<int, int>> dp(m);
        for (int x = 0; x < n; ++x)
        {
            int range = 0;
            for (int y = 0; y < m; ++y)
            {
                if (matrix[y][x])
                    ++range;
                else
                    range = 0;

                ++dp[y][range];
            }
        }


        int result = 0;
        for (int y = 0; y < m; ++y)
        {
            int curCount = 0;
            for (auto it = dp[y].rbegin(); it != dp[y].rend(); ++it)
            {
                curCount += it->second;
                result = std::max(result, curCount * it->first);
            }
        }

        return result;
    }
};