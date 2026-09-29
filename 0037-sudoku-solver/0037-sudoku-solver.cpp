class Solution {
public:

    bool isvalid(vector<vector<char>>& board,int row,int col,char c){
        for(int i=0;i<9;i++){
            if(board[i][col]==c){
                return false;
            }
            if(board[row][i]==c){
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
                return false;
            }
        }
        return true;

    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            board[i][j]=c;
                        
                            if(solve(board)==true){
                                return true;
                            }
                            else{
                                board[i][j]='.';
                            }

                        }
                    }
                    return false;
                }
               
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
// class Solution {
// public:
//     bool isvalid(vector<vector<char>>& board, int row, int col, char c) {
//         for (int i = 0; i < 9; i++) {
//             if (board[i][col] == c) return false;
//             if (board[row][i] == c) return false;
//             if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
//         }
//         return true;
//     }

//     bool solve(vector<vector<char>>& board) {
//         for (int i = 0; i < board.size(); i++) {
//             for (int j = 0; j < board[0].size(); j++) {
//                 if (board[i][j] == '.') {
//                     for (char c = '1'; c <= '9'; c++) {
//                         if (isvalid(board, i, j, c)) {
//                             board[i][j] = c;

//                             if (solve(board)) {
//                                 return true;
//                             } else {
//                                 board[i][j] = '.'; // Backtrack only if placement failed downstream
//                             }
//                         }
//                     }
//                     return false; // Return false if no digit 1-9 works for this empty cell
//                 }
//             }
//         }
//         return true; // All cells filled successfully
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         solve(board);
//     }
// };