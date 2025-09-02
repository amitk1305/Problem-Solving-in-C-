class Solution {
public:
    long long numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        // Step 1: Sort points
        // Sort by x ascending
        // If x is the same, sort by y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];  
            return a[1] > b[1];  
        });

        long long cnt = 0;

        // Step 2: Count valid pairs
        for (int i = 0; i < n; i++) {
            int yi = points[i][1];
            int maxY = INT_MIN; // keeps track of the largest y we've accepted so far

            // Look at all points to the right of i
            for (int j = i + 1; j < n; j++) {
                int yj = points[j][1];

                // Conditions:
                // 1. yj must be lower or equal to yi (point i must be "above")
                // 2. yj must be greater than maxY (strictly lower than the previously chosen minimum)
                //    → ensures we only count when we "step down" in y
                if (yj <= yi && yj > maxY) {
                    cnt++;        
                    maxY = yj;    // update the minimum boundary
                }
            }
        }

        return cnt;
    }
};