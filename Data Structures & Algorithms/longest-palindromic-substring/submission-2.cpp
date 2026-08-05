class Solution {
public:
    string longestPalindrome(string s) {
        
        int sz=s.size(); int n=sz;
        vector<vector<bool>> dp(sz, vector<bool>(sz, false));
        for(int i=0; i<sz; i++){
            dp[i][i]=true;
        }
        int mlen=1, start=0;
        for(int len=2; len<=n; len++){
           for(int i=0;len+i-1<n; i++){
            int j=len+i-1;
            if(s[i]==s[j]){
            if(len==2) dp[i][j]=true;
            else{
                dp[i][j]=dp[i+1][j-1];
            }
            if(dp[i][j]&&len>mlen){
                mlen=len;
                start=i;
            }
            }
           } 
           
        }
        return s.substr(start, mlen);
    }
};
