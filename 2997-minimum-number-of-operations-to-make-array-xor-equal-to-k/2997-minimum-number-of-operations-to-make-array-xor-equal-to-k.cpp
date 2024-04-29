class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
           int r=0,ans=0;
       for(auto &it:nums) r^=it;
       for(int i=0;i<32;i++){
          if((r&1)!=(k&1)) ans++;
          r=r>>1;
          k=k>>1;
       }
       return ans;
    }
};