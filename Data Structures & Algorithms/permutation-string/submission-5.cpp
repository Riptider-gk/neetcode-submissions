class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int ws=s1.length(); int match=0;
        if(ws>s2.length()) return false;
        int l=0; vector<pair<int, int>> freq(26, {0,0}); //s1,s2
        // for(int r=0; r<s2.length(); r++){
        //     freq[s2[r]-'a'].first++;
        // }
        for(int r=0; r<ws; r++){
            freq[s1[r]-'a'].first++;
            freq[s2[r]-'a'].second++;
        }
        //cout<<freq[s2[l]-'a'].second<<" "<<freq[s2[l]-'a'].first<<s2[l]-'a';
        for(int r=0; r<26; r++){
            if(freq[r].first==freq[r].second) match++;
        }
        if(match==26) return true;
        //cout<<"1 "<<freq[s2[l]-'a'].second<<" "<<freq[s2[l]-'a'].first<<s2[l]-'a';
        for(int r=ws; r<s2.length(); r++){
            if (freq[s2[l]-'a'].second==freq[s2[l]-'a'].first) match--;
            freq[s2[l]-'a'].second--;
            if (freq[s2[l]-'a'].second==freq[s2[l]-'a'].first) match++;
            //cout<<" 2 "<<match;
            l++;
            
            if(freq[s2[r]-'a'].second==freq[s2[r]-'a'].first) match--; 
            freq[s2[r]-'a'].second++;
            if(freq[s2[r]-'a'].second==freq[s2[r]-'a'].first) match++; 
            //cout<<" 3 "<<match;
            if(match==26) return true;
        }
        
        return false;
    }
};
