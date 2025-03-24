class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for (int i = 0; i < k; i++) {
            heap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            if (heap.top() < nums[i]) {
                heap.pop();  
                heap.push(nums[i]); 
            }
        }
        
        return heap.top();
    }
};