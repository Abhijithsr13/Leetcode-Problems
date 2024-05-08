class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
          vector<int> ans = score;
        sort(ans.begin(), ans.end(), greater<int>());
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> rankMapping;
        for (int i = 0; i < ans.size(); i++) {
            if (i < 3) {
                rankMapping[ans[i]] = medals[i];
            } else {
                rankMapping[ans[i]] = to_string(i + 1);
            }
        }
        vector<string> result;
        for (int s : score) {
            result.push_back(rankMapping[s]);
        }
        return result;
    }
};