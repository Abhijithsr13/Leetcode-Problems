class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
         // Create a priority queue (min-heap) storing pairs of (value, index)
    priority_queue<pair<int, int>,vector<pair<int, int>>, greater<>> minHeap;

    // Initialize the min-heap with the values and their indices
    for (int i = 0; i < nums.size(); ++i) {
        minHeap.emplace(nums[i], i);
    }

    // Perform k operations
    for (int i = 0; i < k; ++i) {
        // Get the minimum value and its index
        auto [value, index] = minHeap.top();
        minHeap.pop();

        // Update the value in the nums array
        nums[index] *= multiplier;

        // Push the updated value back into the min-heap
        minHeap.emplace(nums[index], index);
    }

    return nums;
    }
};