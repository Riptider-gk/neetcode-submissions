class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> pq;
        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        while(!pq.empty()){
            auto [count, ch] = pq.top();
            pq.pop();

            if(res.size()>1&&res[res.size()-1]==ch&&res[res.size()-2]==ch){
                if(pq.empty()) break;
                auto [count2, ch2]=pq.top();
                pq.pop();
                res+=ch2;
                if(--count2>0) pq.push({count2, ch2});
                pq.push({count, ch});
            }
            else{
                res+=ch;
                if(--count>0) pq.push({count, ch});
            }
        }
        return res;
    }
};