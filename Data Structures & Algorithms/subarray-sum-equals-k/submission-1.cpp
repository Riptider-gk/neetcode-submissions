class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefsum; int sum=0; int curr; int ans=0;
        prefsum[0]=1;
    //     for (const auto& [key, value] : prefsum) {
    //     std::cout << key << ": " << value << "\n";
    // }
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
            curr=sum-k;
            
            
            if(prefsum.find(curr)!=prefsum.end()){
                    ans+=prefsum[curr];
                    
            }
            else prefsum[curr] =0;
            prefsum[sum]++; 
        }
    //     for (const auto& [key, value] : prefsum) {
    //     std::cout << key << ": " << value << "\n";
    // }
        return ans;
    }
};