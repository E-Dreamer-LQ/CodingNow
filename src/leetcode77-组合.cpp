// leetcode77-组合.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/combinations

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	void dfs(int n, int idx, int num) {
		if (idx > n + 1)  return;
		if (tmp.size() == num) {
			res.push_back(tmp);
			return;
		}
		for (int i = idx; i<= n-(num - tmp.size())+1; i++) { // 剪枝： i < n ->> i - 1 + (num- tmp.size()) <= n
			tmp.push_back(i);
			dfs(n, i + 1, num);
			tmp.pop_back();
		}
	}

	vector<vector<int>> combine(int n, int k) {
		dfs(n, 1, k);
		return res;
	}
};
void main() {
	Solution S;
	int n = 4;
	int k = 2;
	vector<vector<int>> res = S.combine(n, k);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[0].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}