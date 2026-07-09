class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); int single=0;
        int ans=0, l=0;int r=people.size()-1;
        // while(people[r]>=limit){
        //     ans++;
        //     l--;
        //     single++;
        // }
        while(l<r){
            int total=people[l]+people[r];
            if(total>limit){
                ans++;
                r--;
                single++;
            }
            else if (total==limit){
                ans++;
                l++; r--;
            }
            else{
                l++;
                
                    ans++;
                    r--;
                
            }
        }
        return ans+((people.size()-single)%2);
    }
};