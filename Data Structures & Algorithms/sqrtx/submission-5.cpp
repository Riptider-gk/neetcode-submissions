class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
        long long l=0, r=x/2; long long res=0;
        while(l<=r){
            long long m=l+(r-l)/2;
            long long a=m*m;
            if(a>x) r=m-1;
            else if(a<x) {
                l=m+1;
                res=m;
                
            }
            else return m;
        }
        return res;
    }
};