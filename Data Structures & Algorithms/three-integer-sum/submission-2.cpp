class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int m, r, sum;
        for(int l=0; l<nums.size()-2; l++){
            m=l+1; r=nums.size()-1;
            if(l>0&&nums[l]==nums[l-1]) continue;
            while(l<m&&m<r){
                sum=nums[l]+nums[r]+nums[m];
                if(sum>0) r--;
                else if (sum<0) m++;
                else if (sum==0) {ans.push_back({nums[l], nums[m], nums[r]}); m++;
r--;

while(m < r && nums[m] == nums[m-1])
    m++;

while(m < r && nums[r] == nums[r+1])
    r--;}
            }
        }
        return ans;
    }
};
