class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
         int m = mat.size();
    int n = mat[0].size();

    // Maps to track row and column counts of painted cells
    vector<int> rowCount(m, 0);
    vector<int> colCount(n, 0);

    // Create a flat mapping of matrix values to their indices in mat
    unordered_map<int, pair<int, int>> positionMap;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            positionMap[mat[i][j]] = {i, j};
        }
    }

    // Process the painting order in arr
    for (int i = 0; i < arr.size(); ++i) {
        auto [row, col] = positionMap[arr[i]]; // Get row and column for current value
        rowCount[row]++;
        colCount[col]++;

        // Check if the current row or column is fully painted
        if (rowCount[row] == n || colCount[col] == m) {
            return i;
        }
    }

    return -1;
    }
};