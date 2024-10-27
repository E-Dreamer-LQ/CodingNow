// leetcode498-对角线遍历.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/diagonal-traverse/

#include <iostream>
#include <vector>
using namespace std;

// 宏观调度问题
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		int M = matrix.size();
		int N = matrix[0].size();
		int tr = 0;
		int tc = 0;
		int dr = 0;
		int dc = 0;
		int endr = M - 1;
		int endc = N - 1;
		bool fromup = false; 
		vector<int> res; 
		while (tr != endr + 1) {
			res = printlevel(matrix, tr, tc, dr, dc, fromup);
			tr = tc == endc ? tr + 1 : tr;
			tc = tc == endc ? tc : tc + 1;
			dr = dr == endr ? dr : dr + 1;
			dc = dr == endr ? dc + 1 : dc;
		}
		return res;

	}
	vector<int> printlevel(vector<vector<int>> matrix, int tr, int tc, int dr, int dc, bool f) {
		vector<int> res; 
		if (f) { // 从上到下
			while (tr != dr + 1) {
				//cout << matrix[tr++][tc--];
				//cout << " ";
				res.push_back(matrix[tr++][tc--]);
			}
		}
		else { // 从下到上
			while (tc != dc + 1) {
				res.push_back(matrix[dr--][dc++]);
			}
		}
		return res; 
	}
};

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		 
        if (matrix.size() == 0 || matrix[0].size()) {
			return {};
	    }
	    int r = 0, c = 0;
	    int row = matrix.size(), col = matrix[0].size();
		vector<int> res(row*col);
	    for (int i = 0; i < res.size(); i++) {
	        res.push_back(matrix[r][c]);
	        // r + c 即为遍历的层数，偶数向上遍历，奇数向下遍历
	        if ((r + c) % 2 == 0) {
	            if (c == col - 1) {
	                // 往下移动一格准备向下遍历
	                r++;
	            } else if (r == 0) {
	                // 往右移动一格准备向下遍历
	                c++;
	            } else {
	                // 往上移动
	                r--;
	                c++;
	            }
	        } else {
	            if (r == row - 1) {
	                // 往右移动一格准备向上遍历
	                c++;
	            } else if (c == 0) {
	                // 往下移动一格准备向上遍历
	                r++;
	            } else {
	                // 往下移动
	                r++;
	                c--;
	            }
	        }
	    }
	    return res;
    }
};

