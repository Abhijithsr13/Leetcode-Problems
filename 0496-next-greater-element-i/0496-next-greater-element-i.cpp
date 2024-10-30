class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
          int n=nums2.size();
        unordered_map<int, int> mpp;
        stack<int>st;
        for(int i=n-1;i>=0;--i){
            while(!st.empty()&& st.top()<=nums2[i])
            st.pop();
            mpp[nums2[i]] = st.empty() ? -1 : st.top();
            
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();++i){
            ans[i]=mpp[nums1[i]];
        }
        return ans;
    }
};