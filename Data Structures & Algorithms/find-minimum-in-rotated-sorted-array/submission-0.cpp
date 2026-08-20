class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0, r=nums.size()-1, m, mid, mn=INT_MAX;
        while(l<=r){
            m=l+(r-l)/2;
            mid=nums[m];
            mn=min(mn,mid);
            if(mid>nums[r]) l=m+1;
            else r=m-1;;
        }
        //cout<<l<<r;
        return mn;
    }
};
