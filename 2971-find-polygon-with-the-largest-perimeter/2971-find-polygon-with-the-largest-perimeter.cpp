class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
     long long  sum=0;
       if(n<3) return -1;
       for(int i=0;i<n;i++){
           sum+=nums[i];
       }
       for(int i = n - 1; i >= 2; i--){
            sum -= nums[i];
            if(sum > nums[i]){
                return sum + nums[i];
            }
        }
        return -1;
    }

};