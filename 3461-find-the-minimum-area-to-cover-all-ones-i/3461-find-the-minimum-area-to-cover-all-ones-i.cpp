class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int col1 = INT_MAX , col2 = INT_MIN , row1 = INT_MAX , row2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    row1 = min(row1 , i);
                    row2 = max(row2 , i);
                    col1 = min(col1 , j);
                    col2 = max(col2 , j);
                }
            }
        }
        return (row2 - row1 + 1) * (col2 - col1 + 1); 
    }
};