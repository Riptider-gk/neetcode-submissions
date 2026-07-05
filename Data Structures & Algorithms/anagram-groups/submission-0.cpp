class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> dict;
        vector<vector<string>> ans;
       for(int i=0; i<strs.size(); i++){
        string ne=strs[i];
        sort(ne.begin(), ne.end());
        if(dict.find(ne)==dict.end()){
        ans.push_back(vector<string> ());
        int idx= ans.size()-1;
        dict[ne]=idx;
        ans[idx].push_back(strs[i]);
        }
        else ans[dict.find(ne)->second].push_back(strs[i]);
        } 
        return ans;
    }
};
