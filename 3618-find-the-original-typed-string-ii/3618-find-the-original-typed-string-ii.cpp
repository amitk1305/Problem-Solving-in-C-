const long long mod = 1e9 + 7;
class Solution {
public:
    int possibleStringCount(string word, int k) {

        // dp[i][s+x_val] = dp[i-1][s]
        // use prefix sum optimisation

        long long count = 1;
        vector<long long> run_encoded;

        for (int i = 1; i < word.size(); i++) {
            if (word[i] == word[i - 1]) {
                count += 1;
            } else {
                run_encoded.push_back(count);
                count = 1;
            }
        }
        run_encoded.push_back(count);

        // all are valid
        if (run_encoded.size() > k) {
            long long ans = 1LL;
            for (auto xi : run_encoded) {
                ans = (ans * xi) % mod;
                ans %= mod;
            }
            return ans%mod;
        }

        // count valid and then remove the invalid
        const int MAX_LENGTH = 5e5 + 5;
        int mxsum = min(k-1, MAX_LENGTH);
        vector<long long> ways_p(mxsum + 1, 0);
        ways_p[0] = 1;
        vector<long long> ways_n(mxsum + 1, 0);
        for (auto xi : run_encoded) {

            vector<long long> prefix(mxsum + 1, 0);
            prefix[0] = ways_p[0];
            
            for (long long s = 1; s <= mxsum; s++)
                (prefix[s] += (prefix[s - 1]%mod + ways_p[s]%mod)%mod)%mod;

            for (long long s = 1; s <= mxsum; s++) {
                long long remain = s - xi;
                ways_n[s] = (prefix[s - 1]%mod - ((remain >= 1) ? prefix[remain - 1] : 0)%mod)%mod;           
                ways_n[s] %= mod;
            }
            ways_p = ways_n;
        }

        long long total = 1;
        for (auto xi : run_encoded) {
            total = (total * xi) % mod;
            total %= mod;
        }

        long long invalid = 0;
        for (long long s = 0; s < k; s++) {
            invalid = (invalid% mod + ways_n[s]% mod) % mod;
            invalid %= mod;
        }

        return (total% mod - invalid%mod + mod)%mod;
    }
};