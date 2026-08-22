class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<int> count={a,b,c};
        string res;

        int repeated=-1;
        while(true){
            int mx=getMax(count, repeated);
            if(mx==-1) break;
            res+=(char)(mx+'a');
            count[mx]--;
            if(res.size()>1&&res.back()==res[res.size()-2]) 
                repeated=mx;
                else repeated=-1;
        }
        return res;
    }
private:
    int getMax(const vector<int>& count, int repeated){
        int idx=-1, mx=0;
        for(int i=0; i<3; i++){
            if(i==repeated||count[i]==0) continue;
            if(mx<count[i]){
                mx=count[i];
                idx=i;
            }
        }
        return idx;
    }
};