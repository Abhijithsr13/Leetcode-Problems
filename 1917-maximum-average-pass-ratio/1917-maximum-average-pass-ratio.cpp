class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](pair<int, int>& a) {
            double pass = a.first, total = a.second;
            return (pass + 1) / (total + 1) - pass / total;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       function<bool(pair<int, int>, pair<int, int>)>>
            pq([&](pair<int, int> a, pair<int, int> b) {
                return gain(a) < gain(b);
            });
        for (auto& c : classes) {
            pq.push({c[0], c[1]});
        }
        while (extraStudents--) {
            auto [pass, total] = pq.top();
            pq.pop();
            pq.push({pass + 1, total + 1});
        }
        double totalAverage = 0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            totalAverage += (double)pass / total;
        }

        return totalAverage / classes.size();
    }
};