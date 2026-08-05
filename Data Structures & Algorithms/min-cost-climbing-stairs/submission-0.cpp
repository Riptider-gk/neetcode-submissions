class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev, prev2, curr;
        prev=0; prev2=0;
        for(int i=2; i<=cost.size(); i++){
            curr=min(prev+cost[i-1], prev2+cost[i-2]);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};
