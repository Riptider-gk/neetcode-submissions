class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int res=0;
        for(const string& op: operations){
            if(op=="+"){
                int top=st.top(); st.pop();
                int newTop=top+st.top();
                st.push(top);
                st.push(top); st.push(newTop);
                res+=newTop;
            } else if (op=="D"){
                st.push(2*st.top());
                res+=st.top();
            } else if (op=="C"){
                res-=st.top();
                st.pop();
            } else {
                st.push(stoi(op));
                res+=st.top();
            }
        }
        return res;
    }
};