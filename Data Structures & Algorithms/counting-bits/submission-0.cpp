class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0; i<=n; i++){
            int c=i;
            while(c){
                c=c&(c-1);
                ans[i]++;
            }
        }
        return ans;
    }
};
