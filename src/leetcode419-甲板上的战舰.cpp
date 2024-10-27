// leetcode419-甲板上的战舰.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countBattleships(vector<vector<char>>& board) {
		int res = 0;
		vector<char> temp;
		for (int i=0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				temp.push_back(board[i][j]);
			}
		}
		for (auto x : temp) {
			if (x == 'X') {
				res++;
			}
		}
		return res; 

	}
};

// 方法二： 这是一个很巧妙的思路，只需要检查一个X的点的左边和上边是否也是X，如果是，则当前X不是战舰，否则战舰数+1，
//这样的话就可以进行一次遍历就好了。
class Solution {
public:
	// 如果board[i][j]的左边或者上边是'X'，返回false.
	bool check(vector<vector<char>>& board, int i, int j) {
		return !((j >= 1 && board[i][j - 1] == 'X') || (i >= 1 && board[i - 1][j] == 'X'));
	}

	int countBattleships(vector<vector<char>>& board) {
		int res = 0;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'X' && check(board, i, j)) res++;
			}
		}
		return res;
	}
};