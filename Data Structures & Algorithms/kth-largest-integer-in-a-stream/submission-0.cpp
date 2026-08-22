class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> mn;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num: nums){
            mn.push(num);
            if(mn.size()>k) mn.pop();
        }
    }
    
    int add(int val) {
        mn.push(val);
        if(mn.size()>k) mn.pop();
        return mn.top();
    }
};
