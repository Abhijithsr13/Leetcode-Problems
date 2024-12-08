class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int n = events.size();
    vector<int> maxUpTo(n, 0); // Maximum value up to each event
    int maxValue = 0;

    // Precompute maxUpTo
    maxUpTo[0] = events[0][2];
    for (int i = 1; i < n; ++i) {
        maxUpTo[i] = max(maxUpTo[i - 1], events[i][2]);
    }

    // Iterate over each event and compute the maximum value
    for (int i = 0; i < n; ++i) {
        int currValue = events[i][2];

        // Find the latest non-overlapping event using binary search
        int left = 0, right = i - 1, idx = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < events[i][0]) {
                idx = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // Add the value of the best non-overlapping event
        if (idx != -1) {
            currValue += maxUpTo[idx];
        }

        // Update the maximum value
        maxValue = max(maxValue, currValue);
    }

    return maxValue;
    }
};