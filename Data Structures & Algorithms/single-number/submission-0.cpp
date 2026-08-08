class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo=0;
        for(int i:nums) xo=xo^i;
        return xo;
    }
};
