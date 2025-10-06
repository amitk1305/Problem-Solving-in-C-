class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, - 1}};
        while (!pq.empty()){
            auto [curr, r, c] = pq.top();
            pq.pop();
            if (r == n - 1 && c == n - 1){
                return curr;
            }
            for (auto& d : dirs){
                int nr = r + d[0], nc = c + d[1];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    pq.push({max(curr, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};