class Solution {
public:
    int speed(int m, vector<int>& piles){
        //find total hours needed to eat
        int ans=0;
        for(int i:piles){
            ans+=(i+m-1)/m;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1, m;
        auto it=max_element(piles.begin(), piles.end());
        int r=*it, res=r;; //cout<<r;
        while(l<=r) {
            m=l+(r-l)/2;
            int c=speed(m, piles);
            if(c>h) l=m+1;
            else  {res=m; r=m-1;}
            //else return m;
        }
        return res;
    }
};
