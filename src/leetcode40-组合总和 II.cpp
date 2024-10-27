// leetcode40-组合总和 II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/combination-sum-ii

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

// 重点如何去除重复
class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	void dfs(vector<int>& candidates, int target, int start) {
		if (target == 0) { 
			res.push_back(temp);   // 终止条件
			return;      
		}
		for (int i = start; i < candidates.size(); i++) {
			if (target - candidates[i] >= 0) {
				if (i != start && candidates[i] == candidates[i - 1]) // 去掉重复
					continue;
				temp.push_back(candidates[i]);
				dfs(candidates, target-candidates[i], i+1);
				temp.pop_back();
			}
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		// 对candidates 排序
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0);
		return res;
		

	}
};

void main() {
	Solution S;
	vector<int> candidates{ 2,5,2,1,2 };
	int target = 5;
	vector<vector<int>> res = S.combinationSum2(candidates, target);
	for (int i = 0; i < res.size(); i++) {

		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

// 利用set来去重
class Solution2 {
public:
	vector<int> tmp;
	vector<vector<int>> res;
	set<vector<int>> s;    // 去除重复的组合
	void dfs(vector<int>& candidates, int target, int start) {
		if (target <= 0) {
			if (target == 0) {
				s.insert(tmp);
			}
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			tmp.push_back(candidates[i]);
			dfs(candidates, target - candidates[i], i + 1);
			tmp.pop_back();
		}
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		dfs(candidates, target, 0);
		for (auto i : s) {
			res.push_back(i);
		}
		return res;
	}
};

// 剪枝
class Solution3 {
public:

	vector<int> input;
	int target;
	vector<vector<int>> result;
	vector<int> vc;

	void dfs(int index, int sum) {
		// index >= input.size() ，写成 index == input.size() 即可
		// 因为每次都 + 1，在 index == input.size() 剪枝就可以了
		if (sum >= target || index == input.size()) {
			if (sum == target) {
				result.push_back(vc);
			}
			return;
		}
		for (int i = index; i < input.size(); i++) {
			// 大剪枝
			if (input[i] > target) {
				continue;
			}

			// 【我添加的代码在这里】：
			// 1、i > index 表明剪枝的分支一定不是当前层的第 1 个分支
			// 2、input[i - 1] == input[i] 表明当前选出来的数等于当前层前一个分支选出来的数
			// 因为前一个分支的候选集合一定大于后一个分支的候选集合
			// 故后面出现的分支中一定包含了前面分支出现的结果，因此剪枝
			// “剪枝”的前提是排序，升序或者降序均可
			if (i > index&& input[i - 1] == input[i]) {
				continue;
			}

			vc.push_back(input[i]);
			sum += input[i];
			dfs(i + 1, sum);
			vc.pop_back();
			sum -= input[i];
		}
	}

	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		// “剪枝”的前提是排序，升序或者降序均可
		sort(candidates.begin(), candidates.end());
		this->input = candidates;
		this->target = target;
		dfs(0, 0);
		return result;
	}
};


