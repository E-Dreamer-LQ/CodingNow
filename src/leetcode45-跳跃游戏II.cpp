// leetcode45-跳跃游戏II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/jump-game-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
	int jump(vector<int>& nums) {
		int res=0;
		int max_jump=0; 
		int tmp = 0; 
		for (int i = 0; i <= max_jump && i < nums.size()-1; i++) { 
			max_jump = max(max_jump, nums[i] + i);
			if (i == tmp) {
				res++;
				tmp = max_jump;  // 上一次跳跃到达 的位置
			}
		}
		return res;
	}
};



bool canjump(vector<int>& nums) {
	int max_jump = 0;
	for (int i = 0; i < nums.size()-1; i++) {
		max_jump = max(max_jump, nums[i] + i);
	}
	if (max_jump < nums.size()-1) {
		return false;
	}
	else {
		return true;
	}
}


// bfs 
class Solution {
public:
	int jump(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		queue<int> que;
		vector<int> visited(nums.size());
		que.push(0);
		int step = 0;
		int n = nums.size();
		while (!que.empty()) {
			int size = que.size();
			step++;
			while (size--) {
				int index = que.front();
				que.pop();
				int max_steps = nums[index];
				if (index + max_steps >= n - 1) return step;
				for (int j = max_steps; j >= 1; j--) {
					if (visited[index + j]) continue;
					que.push(index + j);
					visited[index + j] = 1;
				}
			}
		}
		return -1;
	}
};





void main() {
	vector<int> nums{ 2,3,1,1,4 };
	bool iscanjump = canjump(nums);
	cout << boolalpha << iscanjump << endl;
	Solution S;
	int min_jump = S.jump(nums);
	cout << min_jump << endl;
}

// 别人的好代码
class Solution2 {
public:
	int jump(int[] nums) {
		if (nums.length == 1) return 0;
		int reach = 0;
		int nextreach = nums[0];
		int step = 0;
		for (int i = 0; i < nums.length; i++) {
			nextreach = Math.max(i + nums[i], nextreach);
			if (nextreach >= nums.length - 1) return (step + 1);
			if (i == reach) {
				step++;
				reach = nextreach;
			}
		}
		return step;
	}
}