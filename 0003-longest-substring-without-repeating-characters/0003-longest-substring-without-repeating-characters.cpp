class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int l=0,r=0,cnt=0;
        int n=s.size();
        int hashlen=256;
        int hash[hashlen];
        for (int i = 0; i < hashlen; ++i) {
            hash[i] = -1;
        }
        while(r<n){
           if(hash[s[r]]!=-1){
             if(hash[s[r]]>=l){
              l=hash[s[r]]+1;
             }
           }
           int len=r-l+1;
           cnt=max(cnt,len);
           hash[s[r]]=r;
           r++;
        }
        return cnt;
    }
};