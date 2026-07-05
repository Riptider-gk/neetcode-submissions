class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int f) {
        sort(nums.begin(), nums.end());
        // unordered_map<int, int> mp;
        // for(int num: nums){
        //     mp[num]++;
        // }

        vector<pair<int, int>> arr; int k=0; 
        arr.push_back({1, nums[0]});
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                arr[k].first++;
            }
            else {
                k++;
                arr.push_back({1, nums[i+1]});
                
            }
        }
        sort(arr.begin(), arr.end());

        vector<int> ans;
        
        int siz=arr.size();
        while(f--){
            ans.push_back(arr[siz-1].second); siz--;
        }
        return ans;
    }
};
