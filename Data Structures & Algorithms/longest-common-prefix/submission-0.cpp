class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first = strs[0];
        int i=0;
        for(string s: strs){
            i=0;
            while (i < first.length() && i < s.length() && first[i] == s[i]) {
                i++;
            }
            first.erase(i);
            
        }
        return first;
    }
};