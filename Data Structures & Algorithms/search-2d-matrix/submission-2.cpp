class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()-1, m,c; 
        while(l<=r){
            m=l+(r-l)/2;
            int c=matrix[m][0];
            if(c>target) r=m-1;
            else if (c<target) l=m+1;
            else return true; 
        }
        if(l==0) return false;
        int d=l-1;
        l=0, r=matrix[d].size()-1;
        while(l<=r){
            m=l+(r-l)/2;
            c=matrix[d][m];
            if(c>target) r=m-1;
            else if(c<target) l=m+1;
            else return true;
        }
        return false;
    }
};
