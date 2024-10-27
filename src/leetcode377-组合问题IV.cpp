// leetcode377-组合问题IV.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;


// 可以参考的视频解析：https://www.bilibili.com/video/av45800252
// 回溯法
class Solution {
public:
	vector<vector<int>> res;
	vector<int> temp;
	void dfs(vector<int>& nums, int target) {
		// 遍历条件
		if (target == 0) {
			res.push_back(temp);
			return;
		}
		if (target < 0) {
			return;
		}
		// 开始搜索
		for (int i = 0; i < nums.size(); i++) {
			if (target < nums[i]) continue; // 剪枝
			temp.push_back(nums[i]);
			dfs(nums, target - nums[i]);
		}
	}
	int combinationSum4(vector<int>& nums, int target) {
		dfs(nums, target);
		return res.size();
	}
};

void main() {
	vector<int> nums{1,2,3};
	int target = 4;
	Solution S;
	int res = S.combinationSum4(nums, target);
	cout << res << endl; 
}


