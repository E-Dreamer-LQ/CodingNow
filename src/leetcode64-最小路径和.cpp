// leetcode64-最小路径和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

// 动态规划， dp[i][j] 的值代表直到走到 (i,j)(i,j) 的最小路径和
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = grid[0][0];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 && j != 0)  dp[i][j] = dp[i][j - 1] + grid[i][j];  // 沿着第一行走
				if (i != 0 && j == 0)  dp[i][j] = dp[i - 1][j] + grid[i][j];  // 沿着第一列走
				if (i != 0 && j != 0) {
					// 关键式
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
					//只能向右或向下走，换句话说，当前单元格 (i,j) 只能从左方单元格 (i,j-1)
					//或上方单元格 (i-1,j) 走到，因此只需要考虑矩阵左边界和上边界。
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};

