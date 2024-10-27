// leetcode52-N皇后II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

// 方法一： 直接返回符合要求的n 皇后

class Solution {
public:
	int totalNQueens(int n) {
		vector<string> board(n, string(n, '.'));      //棋盘
		vector<vector<string>> result;              //可行的棋盘
		backtrack(0, board, result);                  //进行回溯求所有可行解
		return result.size();                       //直接返回所有可行解的个数
	}

	void backtrack(int row, vector<string>& board, vector<vector<string>>& result)
	{
		if (row == board.size())
			result.push_back(board);
		else
		{
			for (int col = 0; col < board[0].size(); ++col)
			{
				/*剪枝，避免无效皇后*/
				if (!isVaild(board, row, col))continue;
				/*choose过程：加入决策路径*/
				board[row][col] = 'Q';
				/*row+1选择列表变小，进入下一步选择*/
				backtrack(row + 1, board, result);
				/*unchoose过程：回溯过程，在决策路径中去除决策*/
				board[row][col] = '.';
			}
		}
	}

	bool isVaild(vector<string>& board, int row, int col)
	{
		//检查上方
		for (int i = 0; i < row; ++i)
			if (board[i][col] == 'Q')return false;

		//检查右上方
		for (int i = row - 1, j = col + 1; i >= 0 && j < board[0].size(); i--, j++)
			if (board[i][j] == 'Q')return false;

		//检查左上方
		for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
			if (board[i][j] == 'Q')return false;

		//不用检查下方，因为下方还没有放置皇后
		return true;
	}
};


// 直接回溯
class Solution2 {
public:
	void solve(vector<bool>& cols_, vector<bool>& diag1s_, vector<bool>& diag2s_, int n, int row) {
		if (row == n) { // 到达最后一行了说明找到了一个解法
			count++;
			return;
		}
		for (auto col = 0; col < n; col++) {
			int ll = row + col;
			int rr = row - col + n - 1;
			if (cols_[col] && diag1s_[ll] && diag2s_[rr]) {
				cols_[col] = false;
				diag1s_[ll] = false;
				diag2s_[rr] = false;

				solve(cols_, diag1s_, diag2s_, n, row + 1);

				cols_[col] = true;
				diag1s_[ll] = true;
				diag2s_[rr] = true;
			}
		}
	}

	int totalNQueens(int n) {
		vector<bool> cols_(n, true);
		vector<bool> diag1s_(2 * n - 1, true);
		vector<bool> diag2s_(2 * n - 1, true);
		solve(cols_, diag1s_, diag2s_, n, 0);
		return count;
	}
private:
	int count = 0;
};