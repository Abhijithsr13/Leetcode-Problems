class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
       int maxScore = 0;      // To store the maximum score
    int maxI = values[0];  // Maximum value of values[i] + i seen so far

    for (int j = 1; j < values.size(); ++j) {
        // Calculate the score for the current pair (i, j)
        maxScore = max(maxScore, maxI + values[j] - j);
        // Update maxI for the next iteration
        maxI = max(maxI, values[j] + j);
    }

    return maxScore; 
    }
};