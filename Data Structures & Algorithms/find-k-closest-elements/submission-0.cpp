class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        auto it=lower_bound(arr.begin(), arr.end(), x);
        int index=distance(arr.begin(), it);
        int l=index-1, r=index;
        while (ans.size() < k) {

            if (l < 0) {
                ans.push_back(arr[r]);
                r++;
            }
            else if (r >= arr.size()) {
                ans.push_back(arr[l]);
                l--;
            }
            else if (x - arr[l] <= arr[r] - x) {
                ans.push_back(arr[l]);
                l--;
            }
            else {
                ans.push_back(arr[r]);
                r++;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};