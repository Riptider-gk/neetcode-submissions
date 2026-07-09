class Solution {
public:
    int maxArea(vector<int>& heights) {
        int s=heights.size(), ans=0;
        int l=0, r=s-1; int curr=0;
        while(l<r){
            curr=min(heights[l], heights[r])*(r-l);
            ans=max(curr, ans);
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        cout<<curr;
        return ans;
    }
};
