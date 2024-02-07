class Solution {
public:
    string frequencySort(string s) {
         unordered_map<char, int> mpp;
        priority_queue<pair<int, char> > pq; 
        for (char i : s){
            mpp[i]++;
        }
        for (auto i : mpp){
            pq.push({i.second, i.first});
        }
        string answer = "";
        while (pq.size() != 0){
            for (int i = 0;  i< pq.top().first; i++){
                answer += pq.top().second;
            }
            pq.pop();
        }
        return answer;
    }
};