class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& a, vector<vector<int>>& v,
             int& ri, int& rj) {
        v[i][j] = 1;
        if (i + 1 < a.size() && a[i + 1][j] == 1 && v[i + 1][j] == 0) {
            ri = max(ri, i + 1);
            dfs(i + 1, j, a, v, ri, rj);
        }

        if (j + 1 < a[0].size() && a[i][j + 1] == 1 && v[i][j + 1] == 0) {
            rj = max(rj, j + 1);
            dfs(i, j + 1, a, v, ri, rj);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>&land) {
        vector<vector<int>> ans;

        int i, j;
        vector<vector<int>> v(land.size(), vector<int>(land[0].size(), 0));

        for (i = 0; i < land.size(); i++) {
            for (j = 0; j < land[0].size(); j++) {

                if (!v[i][j] && land[i][j] == 1) {
                    int li = i, lj = j, ri = i, rj = j;

                    dfs(i, j, land, v, ri, rj);

                    ans.push_back({li, lj, ri, rj});
                }
            }
        }

        return ans;
    }
};