class Solution {

public:
    bool box(vector<vector<char>>& board, int i){
        unordered_map<int, bool> mp;
        int c=0;
        for(int n=0; n<3; n++){
            for(int m=0; m<3; m++){
            c=board[(i/3)*3+n][(i%3)*3+m]-'0';
            if(board[(i/3)*3+n][(i%3)*3+m]!='.' && mp.find(c)!=mp.end()) return false;
            mp[c]=true;
        }}
        return true;
    }
    bool row(vector<vector<char>>& board, int col){
        unordered_map<int, bool> mp;
        int c=0;
        for(int i=0; i<9; i++){
            c=board[i][col]-'0';
            if (board[i][col]!='.' && mp.find(c)!=mp.end()) {cout<<"row"; return false;}
            mp[c]=true;
        }
        return true;
    }
    bool column(vector<vector<char>>& board, int row){
        unordered_map<int, bool> mp;
        int c=0;
        for(int i=0; i<9; i++){
            c=board[row][i]-'0';
            if(board[row][i]!='.' && mp.find(c)!=mp.end()) return false;
            mp[c]=true;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool check=true;
        for(int i=0; i<9;i++){
            check=(column(board, i)&&row(board, i)&&box(board, i));
            if(!check) return false;;
        }
        return true;
    }
};
