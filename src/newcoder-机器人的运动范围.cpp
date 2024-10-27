// newcoder-机器人的运动范围.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 


class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		vector<vector<int>> flag(rows, vector<int>(cols, 0));
		return helper(0, 0, rows, cols, flag, threshold);
	}

	int helper(int i, int j, int rows, int cols, vector<vector<int>>& flag_arr, int threshold) { // 一定要& 
		if (i < 0 || i >= rows || j < 0 || j >= cols || count(i) + count(j) > threshold || flag_arr[i][j] == 1) {
			return 0;
		}
		flag_arr[i][j] = 1;
		return helper(i - 1, j, rows, cols, flag_arr, threshold)
			+ helper(i + 1, j, rows, cols, flag_arr, threshold)
			+ helper(i, j - 1, rows, cols, flag_arr, threshold)
			+ helper(i, j + 1, rows, cols, flag_arr, threshold)
			+ 1;
	}
	int count(int n) {
		//int help = 1; 
		int res = 0;
		while (n != 0) {
			res += n % 10;
			n = n / 10;
		}
		return res;
	}

};


void main() {
	Solution S;
	int threshold = 18;
	int cols = 50;
	int rows = 50;
	int res = S.movingCount(threshold,rows,cols );
	cout << res << endl; 

}