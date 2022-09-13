#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int rows[9][256];
int cols[9][256];
int blocks[3][3][256];


bool solve(vector<vector<char>>& board, int i, int j) {
	if (i == 9) return true;
	if (j == 9) return solve(board, i + 1, 0);
	if (board[i][j] != '.') return solve(board, i, j + 1);
	for (char d = '1'; d <= '9'; ++d) {
		if (rows[i][d] || cols[j][d] || blocks[i / 3][j / 3][d]) continue;
		rows[i][d] = cols[j][d] = blocks[i / 3][j / 3][d] = true;
		board[i][j] = d;
		if (solve(board, i, j + 1)) return true;
		board[i][j] = '.';
		rows[i][d] = cols[j][d] = blocks[i / 3][j / 3][d] = false;
	}
	return false;
}

void solveSudoku(vector<vector<char>>& board) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (board[i][j] != '.') {
				char d = board[i][j];
				rows[i][d] = true;
				cols[j][d] = true;
				blocks[i / 3][j / 3][d] = true;
			}
		}
	}
	solve(board, 0, 0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}

}

int main() {
	vector<vector<char>> board(9, vector<char>(9));
	/*
		input:
			. . . . 9 . 2 . 5
			. 1 . . 4 2 6 . 8
			. . . 5 . 8 9 . .
			. 7 . . . . . . .
			. . . . 5 1 7 6 2
			. . . 4 . 3 8 . .
			1 . 2 . . . . . .
			5 9 8 7 . . . . .
			. . 4 . 1 9 . 8 .
	*/
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> board[i][j];
		}
	}
	solveSudoku(board);
	/*
		output:
			6 8 3 1 9 7 2 4 5
			9 1 5 3 4 2 6 7 8
			4 2 7 5 6 8 9 3 1
			8 7 1 9 2 6 3 5 4
			3 4 9 8 5 1 7 6 2
			2 5 6 4 7 3 8 1 9
			1 3 2 6 8 5 4 9 7
			5 9 8 7 3 4 1 2 6
			7 6 4 2 1 9 5 8 3
	*/
}
