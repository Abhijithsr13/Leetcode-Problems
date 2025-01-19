class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0; // No water can be trapped if the grid is too small.

        // Min-heap to store cells in the format: {height, x, y}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        // Visited array to keep track of processed cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the min-heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving to neighboring cells
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int trappedWater = 0;

        while (!pq.empty()) {
            auto [height, cell] = pq.top();
            pq.pop();
            int x = cell.first, y = cell.second;

            for (auto& dir : directions) {
                int nx = x + dir.first, ny = y + dir.second;

                // Skip out-of-bound or already visited cells
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny])
                    continue;

                // Calculate trapped water if the current cell height is higher
                trappedWater += max(0, height - heightMap[nx][ny]);

                // Update the height of the neighbor to the max of its current
                // height or water level
                pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                visited[nx][ny] = true;
            }
        }

        return trappedWater;
    }
};