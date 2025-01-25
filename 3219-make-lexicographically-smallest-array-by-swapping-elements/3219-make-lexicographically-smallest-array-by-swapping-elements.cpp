class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        map<int, queue<int>> levels; // Map of levels to their elements (sorted in queues)
        unordered_map<int, int> levelMap; // Element to level mapping

        // Create a sorted copy of nums to determine levels
        vector<int> sortedNums(nums.begin(), nums.end());
        sort(sortedNums.begin(), sortedNums.end());

        int currentLevel = 0;
        levels[currentLevel].push(sortedNums[0]);
        levelMap[sortedNums[0]] = currentLevel;

        for (int i = 1; i < sortedNums.size(); i++) {
            // If the difference is within the limit, assign to the same level
            if (sortedNums[i] - levels[currentLevel].back() <= limit) {
                levels[currentLevel].push(sortedNums[i]);
            } else {
                // Otherwise, start a new level
                currentLevel++;
                levels[currentLevel].push(sortedNums[i]);
            }
            levelMap[sortedNums[i]] = currentLevel; // Map element to its level
        }

        // Rebuild the original array
        for (int i = 0; i < nums.size(); i++) {
            int elementLevel = levelMap[nums[i]]; // Get the level of the current element
            nums[i] = levels[elementLevel].front(); // Replace with the smallest number in its level
            levels[elementLevel].pop(); // Remove the used number
        }

        return nums;
    }
};