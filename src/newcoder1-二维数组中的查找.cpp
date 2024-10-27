// newcoder1-二维数组中的查找.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		// 二分法 查找
		if (array.size() == 0 || array[0].size() == 0) return 0;
		for (int i = 0; i < array.size(); i++) {
			int l = 0;
			int r = array[i].size() - 1;
			while (l <= r) {
				int mid = (r + l) / 2;
				if (array[i][mid] > target) {
					r = mid - 1;
				}
				else if (array[i][mid] < target) {
					l = mid + 1;
				}
				else {
					return true;
				}
			}
		}
		return false;
	}
};