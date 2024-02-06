class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        
        map<map<char,int>, vector<string>> mpp;
        int n = strs.size();
        string temp;
        
        for(int i=0;i<n;i++)
        {
            map<char,int> temp;
            for(char c:strs[i]){
                temp[c]++;
            }

            mpp[temp].push_back(strs[i]);
        }


        for(auto it=mpp.begin();it!=mpp.end();it++)
        {
            ans.push_back(it->second);
        }

        return ans;

    }
};