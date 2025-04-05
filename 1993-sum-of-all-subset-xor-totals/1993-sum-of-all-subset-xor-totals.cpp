class Solution {
public:
    int n;
    int Xor(int i, int xorsum, vector<int>& nums){
        if (i==n) return xorsum;
        int x=nums[i];
        int take=Xor(i+1, xorsum^x, nums);
        int notake=Xor(i+1, xorsum, nums);
        return take+notake;
    }
    int subsetXORSum(vector<int>& nums) {
        n=nums.size();
        return Xor(0, 0, nums);
    }
};