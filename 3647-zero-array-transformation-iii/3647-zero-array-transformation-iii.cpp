class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());  // Sort queries by start index
        priority_queue<int> pq;  // Max heap to store query end indices
        
        int n = nums.size();
        int current = 0;
        vector<int> sweep(n + 1, 0);  // Difference array for efficient updates

        for(int i = 0; i < n; i++) {
            if(i != 0)
                sweep[i] += sweep[i - 1];  // Apply cumulative removal effect
            
            // Process all queries that start at index `i`
            while(current < queries.size() && queries[current][0] <= i) {
                pq.push(queries[current][1]);  // Push end index
                current++;
            }

            // Remove elements based on the priority queue constraints
            while(sweep[i] < nums[i]) {
                if(pq.empty() || pq.top() < i) return -1;  // Invalid case
                
                sweep[i]++;  // Apply removal
                sweep[pq.top() + 1]--;  // Mark end of removal range
                pq.pop();
            }
        }

        return pq.size();  // Remaining queries in the heap
    }
};