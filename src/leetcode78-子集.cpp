// leetcode78-子集.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

// 回溯法
class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	vector<vector<int>> subsets(vector<int>& nums) {
		dfs(nums,0);
		return res; 
	}
	void dfs(vector<int>& nums,int start) {
		if (temp.size() <= nums.size()) {
			res.push_back(temp);
		}
		else {
			return;
		}

		for (int i = start; i < nums.size(); i++) {
			temp.push_back(nums[i]);
			dfs(nums, i + 1);
			temp.pop_back();
		}
	}
};

class Solution2 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int> > res(1);
		for (int i = 0; i < nums.size(); i++) {
			int cnt = res.size();
			for (int j = 0; j < cnt; j++) {
				vector<int> tmp = res[j];
				tmp.push_back(nums[i]);
				res.push_back(tmp);
			}
		}
		return res;
	}
}; 



// 位运算   niubility 
class Solution3 {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int S = nums.size();
		int N = 1 << S;
		vector<vector<int> > res;
		for (int i = 0; i < N; ++i) {
			vector<int> v;
			for (int j = 0; j < S; ++j)
				if (i & (1 << j))
					v.push_back(nums[j]);
			res.push_back(v);
		}
		return res;
	}
};


void main() {
	Solution S;
	vector<int> nums{ 1,2,3 };
	vector<vector<int>> res = S.subsets(nums);
	Solution2  S2;
	vector<vector<int>> res2 = S2.subsets(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[0].size(); j++) {
			cout << res[i][j];
		}
	}
	for (int i = 0; i < res2.size(); i++) {
		for (int j = 0; j < res2[0].size(); j++) {
			cout << res2[i][j];
		}
	}
}


