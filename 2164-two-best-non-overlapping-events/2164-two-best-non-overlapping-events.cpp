class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by end time
        sort(events.begin(), events.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int n = events.size();
        vector<int> maxUpTo(n, 0); // Stores the maximum value up to each event
        int maxValue = 0;

        for (int i = 0; i < n; ++i) {
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

            // Calculate max value for the current event
            int currValue = events[i][2];
            if (idx != -1) {
                currValue += maxUpTo[idx];
            }

            // Update the running maximum value
            maxValue = max(maxValue, currValue);

            // Store the maximum value up to the current event
            if (i == 0) {
                maxUpTo[i] = events[i][2];
            } else {
                maxUpTo[i] = max(maxUpTo[i - 1], events[i][2]);
            }
        }

        return maxValue;
    }
};