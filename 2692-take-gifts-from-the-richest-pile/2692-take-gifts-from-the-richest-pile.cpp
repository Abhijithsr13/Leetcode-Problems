class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        for (int i = 0; i < k; ++i) {
            // Extract the largest pile
            int maxGift = maxHeap.top();
            maxHeap.pop();
            // Calculate the remaining gifts
            int remaining = floor(sqrt(maxGift));
            // Push the remaining gifts back into the heap
            maxHeap.push(remaining);
        }

        // Calculate the total number of gifts remaining
        long long total = 0;
        while (!maxHeap.empty()) {
            total += maxHeap.top();
            maxHeap.pop();
        }

        return total;
    }
};