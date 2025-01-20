class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         int m = mat.size();
    int n = mat[0].size();

    // Map each value in mat to its row and column
    unordered_map<int, pair<int, int>> valueToPos;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            valueToPos[mat[i][j]] = {i, j};
        }
    }

    // Track row and column counts
    vector<int> rowPaintCount(m, 0);
    vector<int> colPaintCount(n, 0);

    // Process each value in arr
    for (int i = 0; i < arr.size(); ++i) {
        int value = arr[i];
        auto [row, col] = valueToPos[value];

        // Increment the counts for the row and column
        rowPaintCount[row]++;
        colPaintCount[col]++;

        // Check if the row or column is completely painted
        if (rowPaintCount[row] == n || colPaintCount[col] == m) {
            return i;
        }
    }

    return -1;
    }
};