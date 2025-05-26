class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<uint8_t> col(n);
        for (int i = 0; i < n; ++i)
            col[i] = colors[i] - 'a';
        vector<int> indeg(n), outdeg(n);
        for (auto &e : edges) {
            outdeg[e[0]]++;
            indeg[e[1]]++;
        }
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i)
            adj[i].reserve(outdeg[i]);
        for (auto &e : edges)
            adj[e[0]].push_back(e[1]);
        // dp[u][c] = max count of color c on any path ending at u
        vector<array<int,26>> dp(n);
        vector<int> q(n);
        int head = 0, tail = 0;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                dp[i][col[i]] = 1;
                q[tail++] = i;
            }
        }
        int seen = 0, ans = 0;
        while (head < tail) {
            int u = q[head++];
            ++seen;
            auto &dp_u = dp[u];
            int local_max = 0;
            for (int c = 0; c < 26; ++c) {
                if (dp_u[c] > local_max)
                    local_max = dp_u[c];
            }
            if (local_max > ans)
                ans = local_max;
            for (int v : adj[u]) { // relax edges
                auto &dp_v = dp[v];
                uint8_t cv = col[v];
                for (int c = 0; c < 26; ++c) {
                    int candidate = dp_u[c] + (c == cv);
                    if (candidate > dp_v[c])
                        dp_v[c] = candidate;
                }
                if (--indeg[v] == 0) 
                    q[tail++] = v;
            }
            dp[u] = array<int,26>{}; // free row u
        }
        return (seen == n ? ans : -1);
    }
};


//         int n = colors.size();
//         vector<int> col(n);
//         for (int i = 0; i < n; ++i)
//             col[i] = colors[i] - 'a';
//         vector<vector<int>> adj(n);
//         vector<int> indeg(n, 0);
//         for (auto& e : edges) {
//             int u = e[0], v = e[1];
//             adj[u].push_back(v);
//             ++indeg[v];
//         }
//         vector<array<int,26>> dp(n);
//         queue<int> q;
//         for (int i = 0; i < n; ++i) {
//             if (indeg[i] == 0) {
//                 q.push(i);
//                 dp[i][col[i]] = 1;
//             }
//         }
//         int seen = 0, ans = 0;
//         while (!q.empty()) {
//             int u = q.front(); q.pop();
//             ++seen;
//             int au = *max_element(dp[u].begin(), dp[u].end());
//             ans = max(ans, au);
//             for (int v : adj[u]) {
//                 int cv = col[v];
//                 for (int c = 0; c < 26; ++c) {
//                     int val = dp[u][c] + (c == cv);
//                     dp[v][c] = max(dp[v][c], val);
//                 }
//                 if (--indeg[v] == 0)
//                     q.push(v);
//             }
//         }
//         return seen == n ? ans : -1;
//     }
// };