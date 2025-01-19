class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2)
            return 0; // No space for trapping water in small grids.

        // Min-heap to store cells as {height, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        // Add boundary cells to the heap and mark them visited by setting their
        // height to -1
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.push({heightMap[i][j], i * n + j});
                    heightMap[i][j] = -1; // Mark as visited
                }
            }
        }

        // Directions for moving to neighboring cells
        vector<int> directions = {-1, 0, 1, 0, -1}; // Combines dx and dy

        int trappedWater = 0;

        while (!pq.empty()) {
            auto [height, idx] = pq.top();
            pq.pop();

            int x = idx / n, y = idx % n;

            for (int d = 0; d < 4; ++d) {
                int nx = x + directions[d], ny = y + directions[d + 1];

                // Check boundaries and if the cell is already visited
                if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                    heightMap[nx][ny] == -1)
                    continue;

                // Calculate trapped water for the neighboring cell
                trappedWater += max(0, height - heightMap[nx][ny]);

                // Push the updated cell into the heap and mark it as visited
                pq.push({max(height, heightMap[nx][ny]), nx * n + ny});
                heightMap[nx][ny] = -1; // Mark as visited
            }
        }

        return trappedWater;
    }
};