class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        for(int i=0;i<n;i++){
            if(l<i) return false;
            l=max (l,i+nums[i]);
        }
        return true;
            
    }
};