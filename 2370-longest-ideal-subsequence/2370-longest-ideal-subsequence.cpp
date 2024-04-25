class Solution {
public:
    int longestIdealString(string s, int k) {
        int map[27] = {0};
        int n = s.length();

        for (int i = n - 1; i >= 0; i--) {
            char cc = s[i];
            int idx = cc - 'a';
            int maxi = -__INT_MAX__;

            int left = max((idx - k), 0);
            int right = min((idx + k), 26);

            for (int j = left; j <= right; j++) {
                maxi = max(maxi, map[j]);
            }

            map[idx] = maxi + 1;
        }

        int max = -__INT_MAX__;
        for (int i = 0; i < 27; i++) {
            if (map[i] > max)
                max = map[i];
        }

        return max;
    }
};