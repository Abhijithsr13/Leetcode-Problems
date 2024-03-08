class Solution {
public:
    bool isIsomorphic(string s, string t) {
       if(s.size()!=t.size()) return false;
        unordered_map<char,char> mpp,mpp1;
        for(int i=0;i<s.length();++i){
           if (mpp[s[i]] && mpp[s[i]]!=t[i]) return false;
           if (mpp1[t[i]] && mpp1[t[i]]!=s[i]) return false;
           mpp[s[i]]=t[i];
           mpp1[t[i]]=s[i];
        }
        return true;
    }
};