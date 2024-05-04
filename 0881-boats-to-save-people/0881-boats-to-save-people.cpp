class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int cnt=0;
        for(int l=0, r=n-1;l<=r; r--){
            cnt++;
            if (people[l]<=limit-people[r])
                l++;          
        }
        return cnt;
    }
};