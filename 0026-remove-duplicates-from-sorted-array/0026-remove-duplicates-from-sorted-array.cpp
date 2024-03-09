class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       /* int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;*/
        set<int>s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int k=s.size();
        int j=0;
        for(auto it:s){
            nums[j++]=it;
        }
        return k;
    }
};