class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int>s;
        int ans = 0;
        int maxEle = INT_MIN;
        for(int i = 0 ;i < nums.size();i++){
            maxEle = max(maxEle , nums[i]);
            if(nums[i] >0 && !s.count(nums[i]) ){
                ans += nums[i];
                s.insert(nums[i]);
            }
        }

        return ans == 0 ? maxEle : ans;
    }
};