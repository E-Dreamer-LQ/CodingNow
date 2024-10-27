// leetcode39-组合总和.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		dfs(candidates, 0, target);
		return res;
	}
	void dfs(vector<int> candidates, int start, int target) {
		if (target <= 0) {
			if (target == 0) {
				res.push_back(temp);
			}
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			temp.push_back(candidates[i]);
			dfs(candidates, i, target - candidates[i]);
			temp.pop_back();
		}
	}
};

void main() {
	Solution S;
	vector<int> candidates{2,3,5};
	int target = 8;
	vector<vector<int>> res = S.combinationSum(candidates, target);
}

