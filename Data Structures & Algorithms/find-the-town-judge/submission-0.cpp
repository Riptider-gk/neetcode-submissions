class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         
        int s=trust.size();
        vector<int> by(n+1,0); vector<int> to(n+1,0);
        for(int i=0; i<s; i++){
            by[trust[i][0]]++;
            to[trust[i][1]]++;
            
        }
        for(int i=0; i<n+1; i++){
            if(to[i]==n-1&&by[i]==0) return i;
        }
        return -1;
    }
};