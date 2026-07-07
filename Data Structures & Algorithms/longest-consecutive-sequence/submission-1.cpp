class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int cnt=0; int tot=0;
        for(int i=1; i<nums.size(); i++){
            if((nums[i]-nums[i-1])==1) {cnt++; cout<<cnt;}
            else if ((nums[i]-nums[i-1])==0) continue;
            else {tot=max(tot, cnt); cnt=0;}
        }
        tot=max(tot, cnt); cnt=0;
        return tot+1;
    }
};
