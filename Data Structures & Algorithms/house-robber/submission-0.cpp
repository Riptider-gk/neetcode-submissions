class Solution {
public:
    vector<int> memo;
    int rec(vector<int>& nums, int i){
        
        if(i>=nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        memo[i]=max(rec(nums, i+1), nums[i]+rec(nums, i+2));
        return memo[i];
    }
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return rec(nums, 0);
    }
};
