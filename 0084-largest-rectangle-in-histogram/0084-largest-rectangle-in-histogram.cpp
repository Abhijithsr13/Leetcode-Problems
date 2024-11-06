class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         stack<int>st;
     int maxi=0;
     int area;
     int nse,pse;
     int n=heights.size();
     for(int i=0;i<n;i++){
        while(!st.empty() && 
        heights[st.top()]>=heights[i]){
            int ele=st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            nse=i;
             area = heights[ele] * (nse-pse-1);
             maxi=max(maxi,area);
        }
        st.push(i);
     }
     while(!st.empty()){
        nse=n;
        int ele=st.top();
        st.pop();
        pse=st.empty()?-1:st.top();
        area = heights[ele] * (nse-pse-1);
         maxi=max(maxi,area);
     }
     return maxi;
    }
};