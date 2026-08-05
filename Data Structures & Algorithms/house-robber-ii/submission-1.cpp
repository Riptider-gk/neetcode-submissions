class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int prev=0, prev1=0, curr;
        for(int i=0; i<nums.size()-1; i++){
            curr=max(prev, prev1+nums[i]);
            prev1=prev;
            prev=curr;
        }
        int ans1=prev;
        prev=0; prev1=0; curr=0;
        for(int i=1; i<=nums.size()-1; i++){
            curr=max(prev, prev1+nums[i]);
            prev1=prev;
            prev=curr;
        }
        return max(prev, ans1);
    }
};
