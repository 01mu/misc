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
        int x,  y, temp;
        char ch;

        for(y = 0; y < y_len; y++) {
            for(x = 0; x < x_len; x++) {
                ch = board[y][x];

                if(ch == 'x') {
                   if(board[y][x+1] == 'x') {
                        temp = x;

                        while(board[y][temp] == 'x') {
                            board[y][temp++] = '.';
                        }
                    } else if(y < y_len-1 && board[y+1][x] == 'x') {
                        temp = y;

                        do {
                            board[temp++][x] = '.';
                        } while(temp < y_len && board[temp][x] == 'x');
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
    vector<vector<char>> board(  {{'x', '.', '.', 'x'},
                                {'.', '.', '.', 'x'},
                                {'.', '.', '.', 'x'}});

    Solution solution;

    cout << solution.countBattleships(board);
}
