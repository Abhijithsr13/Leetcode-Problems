class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        auto comp = [&arr](const std::pair<int, int>& a,
                           const std::pair<int, int>& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };

        std::priority_queue<std::pair<int, int>,
                            std::vector<std::pair<int, int>>, decltype(comp)>
            pq(comp);

        for (int i = 0; i < arr.size() - 1; ++i) {
            pq.emplace(i, arr.size() - 1);
        }

        for (int i = 1; i < k; ++i) {
            auto top = pq.top();
            pq.pop();
            int numeratorIndex = top.first;
            int denominatorIndex = top.second;

            if (denominatorIndex - 1 > numeratorIndex) {
                pq.emplace(numeratorIndex, denominatorIndex - 1);
            }
        }

        auto result = pq.top();
        return {arr[result.first], arr[result.second]};
    }
};