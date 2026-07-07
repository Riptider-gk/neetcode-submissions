class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s=nums.size();
        vector<int> ans(s, 1);
        for(int i=1; i<s; i++){
            ans[i]=ans[i-1]*nums[i-1];
        }
        int res=nums[s-1];
        for(int i=s-2; i>=0; i--){
            ans[i]*=res;
            res*=nums[i];
        }
        return ans;
    }
};
