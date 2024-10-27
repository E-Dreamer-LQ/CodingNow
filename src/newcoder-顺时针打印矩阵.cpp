// newcoder-顺时针打印矩阵.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

using namespace std;
class Solution {   //  OJ 时超出了内存限制
public:
	vector<int> res;
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int M = matrix.size() - 1;
		int N = matrix[0].size() - 1;
		int dr = 0;
		int dc = 0;
		int tr = M;
		int tc = N;
		while (dr <= tr && dc <= tc) {
			if (dr == tr) {   // 如果只有一行
				for (int i = dc; i <= tc; i++) {
					res.push_back(matrix[dr][i]);
				}
			}
			else if (dc == tc) {   // 如果只有一列
				for (int i = dr; i <= tr; i++) {
					res.push_back(matrix[i][tc]);
				}
			}
			else {
				int cur_r = dr;
				int cur_c = dc;
				while (cur_c != tc) {
					res.push_back(matrix[dr][cur_c]);
					cur_c++;
				}
				while (cur_r != tr) {
					res.push_back(matrix[cur_r][tc]);
					cur_r++;
				}
				while (cur_c != dc) {
					res.push_back(matrix[tr][cur_c]);
					cur_c--;
				}
				while (cur_r != dr) {
					res.push_back(matrix[cur_r][dc]);
					cur_r--;
				}
				dr++; tr--; dc++; tc--;
			}
		}
		return res;
	}
};


class Solution2 {
public:
	vector<int> printMatrix(vector<vector<int> > matrix) {
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> res;

		// 输入的二维数组非法，返回空的数组
		if (row == 0 || col == 0)  return res;

		// 定义四个关键变量，表示左上和右下的打印范围
		int left = 0, top = 0, right = col - 1, bottom = row - 1;
		while (left <= right && top <= bottom)
		{
			// left to right
			for (int i = left; i <= right; ++i)  res.push_back(matrix[top][i]);
			// top to bottom
			for (int i = top + 1; i <= bottom; ++i)  res.push_back(matrix[i][right]);
			// right to left
			if (top != bottom)
				for (int i = right - 1; i >= left; --i)  res.push_back(matrix[bottom][i]);
			// bottom to top
			if (left != right)
				for (int i = bottom - 1; i > top; --i)  res.push_back(matrix[i][left]);
			left++, top++, right--, bottom--;
		}
		return res;
	}
};


void main() {
	Solution S;
	Solution2 S2; 
	vector<vector<int>> matrix{ {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int> res = S.printMatrix(matrix);
	vector<int> res2 = S2.printMatrix(matrix);
	for (auto num : res) {
		cout << num;
		cout << " ";
	}
	cout << endl;
	for (auto num : res2) {
		cout << num;
		cout << " ";
	}
}