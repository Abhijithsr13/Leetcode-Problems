class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=0;
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
            n=max(n,mpp[it]);
        }
        vector<vector<int>>ans(n);
        vector<set<int>>st(n);
         for( auto it : nums){
          for(int i=0;i<n;i++){
              if(st[i].find(it)==st[i].end()){
                  ans[i].push_back(it);
                  st[i].insert(it);
                   break;
              }
          }
         }
         return ans;
    }
        
};