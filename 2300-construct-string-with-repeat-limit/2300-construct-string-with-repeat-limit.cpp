class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
         vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Step 2: Use a max-heap to keep track of characters and their frequencies
    priority_queue<pair<char, int>> maxHeap;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            maxHeap.push({char('a' + i), freq[i]});
        }
    }

    string result;
    while (!maxHeap.empty()) {
        auto [currChar, currCount] = maxHeap.top();
        maxHeap.pop();

        int useCount = min(repeatLimit, currCount);  
        result.append(useCount, currChar);
        currCount -= useCount;

        if (currCount > 0) {
            if (maxHeap.empty()) break; 

            auto [nextChar, nextCount] = maxHeap.top();
            maxHeap.pop();

            result.push_back(nextChar);  
            nextCount--;
            if (nextCount > 0) {
                maxHeap.push({nextChar, nextCount});
            }
            maxHeap.push({currChar, currCount});
        }
    }

    return result;
    }
};