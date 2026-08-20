class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l= *max_element(weights.begin(), weights.end());int r,m, c, d, curr=0, res; 
        for(int i: weights) r+=i;
        while(l<=r){
            d=1;
            m=l+(r-l)/2;
            curr=0;
            for(int i:weights){
                if(curr+i>m){
                    d++;
                    curr=0;
                }
                curr+=i;
            }
            if(d>days) l=m+1;
            else {
                
                r=m-1;
            }
        }
        return l;
    }
};