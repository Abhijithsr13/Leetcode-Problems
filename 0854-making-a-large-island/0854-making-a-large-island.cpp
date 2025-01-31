class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
          int n = grid.size();
        vector<int> area = {0, 0};
        int islandId = 2;
       
        auto dfs = [&](int r, int c, int id, auto& dfs) -> int {
            if (r < 0 || c < 0 || r >= n || c >= n || grid[r][c] != 1) return 0;
            grid[r][c] = id;
            return 1 + dfs(r + 1, c, id, dfs) 
                     + dfs(r - 1, c, id, dfs) 
                     + dfs(r, c + 1, id, dfs) 
                     + dfs(r, c - 1, id, dfs);
    };
            for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 1) {
                    area.push_back(dfs(r, c, islandId, dfs));
                    islandId++;
                }
            }
        }
    
        int maxIsland = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    unordered_set<int> seen; 
                    int newIsland = 1; 
                    for (auto [dr, dc] : vector<pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
                        int nr = r + dr, nc = c + dc;
                        if (nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] > 1) {
                            int id = grid[nr][nc];
                            if (seen.insert(id).second) { 
                                newIsland += area[id];
                            }
                        }
                    }
                    maxIsland = max(maxIsland, newIsland);
                }
            }
        }
      
        return maxIsland == 0 ? n * n : max(maxIsland, *max_element(area.begin(), area.end()));
    }
};