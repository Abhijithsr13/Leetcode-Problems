class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        const int n=nums.size();
        int maxSum=0, sum=nums[0];
        for(int r=1; r<n; r++){
            if (nums[r]>nums[r-1]) sum+=nums[r];
            else{
                maxSum=max(maxSum, sum);
                sum=nums[r];
            }
        }
        return max(maxSum, sum);
    }
};