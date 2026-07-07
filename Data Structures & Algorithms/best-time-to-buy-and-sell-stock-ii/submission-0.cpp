class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr; int next; int tot=0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i]>prices[i-1]){
                tot+=prices[i]-prices[i-1];
            }
        }
        return tot;
    }
};