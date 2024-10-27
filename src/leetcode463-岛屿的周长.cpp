// leetcode463-岛屿的周长.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		multiset<int> rb(grid.begin(),grid.end());
		int num_1 = rb.count(1);
		int W = grid.size();
		int H = grid[0].size();
		return (H * W) - num_1 + 1;
	}
};


void main() {
	vector<int> temp(5);
	vector<vector<int> > matrix(4, temp);
	cout << "row:" << matrix.size() << endl;
	cout << "column:" << matrix[0].size() << endl;
	cout << "[" << endl;
	for (int i = 0; i < matrix.size(); ++i) {
		cout << "[" << " ";
		for (int j = 0; j < matrix[0].size(); ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << "]" << endl;
	return ;
}