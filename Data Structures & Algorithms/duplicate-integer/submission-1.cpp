class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        long long int prev=INT_MAX;
        sort(nums.begin(), nums.end());
        for(long long int val: nums){
            if(prev==val) return true;
            prev=val;
        }
        return false;
    }
};