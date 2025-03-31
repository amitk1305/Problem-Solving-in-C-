class Solution {
public:
    int putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;  // If k == 1, only one partition is possible, so no difference.

        vector<int> pairSums;
        for (int i = 0; i < n - 1; i++) {
            pairSums.push_back(weights[i] + weights[i + 1]);
        }
        
        sort(pairSums.begin(), pairSums.end());

        long long maxSum = 0, minSum = 0;
        for (int i = 0; i < k - 1; i++) {
            minSum += pairSums[i];                 // Smallest k-1 pair sums
            maxSum += pairSums[n-2-i];             // Largest k-1 pair sums
        }

        return maxSum - minSum;
    }
};
