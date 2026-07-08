class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev=nums[0]; int ans=1; 
        for(int i=1; i<nums.size(); i++){
            if(prev==nums[i]) {
            
            nums.erase(nums.begin()+i);
            i--;
            }
            else {prev=nums[i]; ans++;}
        }
        return ans;
    }
};