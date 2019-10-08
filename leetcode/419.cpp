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

        for(int y = 0; y < y_len; y++) {
            for(int x = 0; x < x_len; x++) {
                char ch = board[y][x] ;

                if(ch == 'X') {
                   if(board[y][x+1] == 'X') {
                        int z = x;

                        while(board[y][z] == 'X') {
                            board[y][z] = '.';
                            z++;
                        }
                    } else if(y < y_len-1 && board[y+1][x] == 'X') {
                        int z = y;

                        do {
                            board[z][x] = '.';
                            z++;

                        } while(z < y_len && board[z][x] == 'X');
                    }

                    count++;
                    board[y][x] = '.';
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<char>> board(  {{'X', '.', '.', 'X', 'X'},
                                {'X', '.', 'X', '.', '.'},
                                {'X', '.', 'X', '.', 'X'}});

    Solution solution;

    cout << solution.countBattleships(board);
}
