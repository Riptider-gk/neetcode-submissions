class Solution {
public:
    int tribonacci(int n) {
        if(n<3) {if(n!=0) {return 1;} return 0;}
        int prev=1, prev2=1, prev3=0, curr;
        for(int i=3; i<=n; i++){
            curr=prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            
            prev=curr;
        }
        return prev;
    }
};