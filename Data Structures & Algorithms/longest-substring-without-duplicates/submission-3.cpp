class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r=0, l=0;
        int ans = 0; int curr=0;
        unordered_map<char,int> mp;
        //mp[s[0]]=1;
        if(s.length()==0) return 0;
        if(s.length()==1) return 1;
        while(r<s.length()){
            
            while(mp[s[r]]!=0&&l<r){
                mp[s[l++]]--;
            }
            mp[s[r]]++;
            curr=r-l+1;
            ans=max(curr, ans);
            r++;
        }
        return ans;
    }
};
