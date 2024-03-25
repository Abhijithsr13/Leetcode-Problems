class Solution {
public:
vector<vector<int>> ans;
int n;
void findSubset(vector<int>&subset,vector<int>&nums,int startIndex){
    if(startIndex ==n){
        ans.push_back(subset);
        return;
    }
    subset.push_back(nums[startIndex]);
    findSubset(subset,nums,startIndex+1);
    subset.pop_back();
    findSubset(subset,nums,startIndex+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
           vector <int>subset;
           n=nums.size();
           findSubset(subset,nums,0);
           return ans;
            }
};