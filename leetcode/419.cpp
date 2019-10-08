/*
 * https://leetcode.com/problems/battleships-in-a-board/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int x_len = board[0].size();
        int y_len = board.size();

        int count = 0;

        for(int i = 0; i < y_len; i++) {
            for(int j = 0; j < x_len; j++) {
                if(board[i][j] == 'X') {
                    /*if(board[i][j-1] == 'X') {
                        cout << i << " " << j << endl;
                    } else if(i >= 0 || board[i-1][j] == 'X') {
                        cout << i << " " << j << endl;
                    } */

                    if(board[i][j+1] == 'X') {  /* right */
                        scan(board, j, i, 'r');
                    } else if(i < y_len-1 && board[i+1][j] == 'X') {  /* down */
                        scan(board, j, i, 'd');
                    }

                    count++;
                }
            }
        }

        return count;
    }

    void scan(vector<vector<char>>& board, int x, int y, char dir) {


    }
};

int main()
{
    vector<vector<char>> board(  {{'X', '.', 'X', 'X'},
                                {'X', '.', '.', '.'},
                                {'.', '.', '.', '.'}});

    Solution solution;

    cout << endl << solution.countBattleships(board);
}
