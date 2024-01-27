class Solution {
public:
   int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n + 1, vector<int>(k+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 0; j < i; ++j){ // In number i, we can create 0 ~ i-1 inverse pairs 
                for(int m = 0; m <= k; ++m){ //dp[i][m] +=  dp[i-1][m-j]
                    if(m - j >= 0 && m - j <= k){
                        dp[i][m] = (dp[i][m] + dp[i-1][m-j]) % mod; 
                    }
                }
            }
        }
        return dp[n][k];
    }
private:
    const int mod = pow(10, 9) + 7;
};