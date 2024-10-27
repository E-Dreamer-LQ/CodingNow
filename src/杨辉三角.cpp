// 杨辉三角.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 


// 动态规划
class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> res(numRows);
		if (numRows == 0)return res;
		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (j == 0 || j == i)   // 第一行初始化为1，和两边为1 
					res[i].push_back(1);
				else
					res[i].push_back(res[i - 1][j - 1] + res[i - 1][j]);
			}
		}
		return res;
	}
};

void main() {
	Solution S;
	int numRows = 5;
	vector<vector<int>> res = S.generate(numRows); 
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j]; 
		}
	}
}
