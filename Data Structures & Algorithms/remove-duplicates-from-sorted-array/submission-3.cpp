class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
    return 0;
        int pos=1; int prev=nums[0]; int k=1;
        for (int i=1; i<nums.size(); i++){
            if (prev==nums[i]){
                ;
            } else {
                nums[pos]=nums[i]; k++; pos++;
            }
            prev=nums[i];
        }
        return k;
    }
};