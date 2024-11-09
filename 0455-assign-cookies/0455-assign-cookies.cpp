class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
         int n = g.size();
        int m = s.size();
        int l =0;
        int r=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        while(l<n&&r<m){
           if(s[r]>=g[l]){
          l++;  
           }
        r++;
         }
        return l;
    }
};