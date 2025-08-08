class Solution {
public:
    double dp[201][201];
    double dfs(int a, int b){
        if (a <= 0 && b > 0){
            return 1.0;
        }
        if (a <= 0 && b <= 0){
            return 0.5;
        }
        if (a > 0 && b <= 0){
            return 0.0;
        }
        if (dp[a][b] != -1.0){
            return dp[a][b];
        }
        double res = 0.25 * (
            dfs(a - 4, b) + 
            dfs(a - 3, b - 1) + 
            dfs(a - 2, b - 2) + 
            dfs(a - 1, b - 3)
        );
        return dp[a][b] = res;
    }
    double soupServings(int n) {
        if (n > 5000){
            return 1.0;
        }
        std::fill(&dp[0][0], &dp[0][0] + 201*201, -1.0);
        int N = (int)std::ceil(n / 25.0);
        return dfs(N, N);
    }
};