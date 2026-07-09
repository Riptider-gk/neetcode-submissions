class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        //first reverse the array
        k %= nums.size();
        int s=nums.size();
        for(int i=0; i<s/2; i++){
            swap(nums[i], nums[s-i-1]);
        }
        //now again reverse the first k elements and the rest of the elements individually
        for(int i=0; i<k/2; i++){
            swap(nums[i], nums[k-i-1]);
        }
        for(int i=k; i-k<(s-k)/2; i++){
            swap(nums[i], nums[s-i-1+k]);
        }
    }
};