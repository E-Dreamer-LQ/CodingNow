// leetcode376-摆动序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


/*
贪心算法，如果nums[i] > nums[i-1]，表示一个向上增长，即up = down + 1。
假设之前的是一个下降趋势的序列长度！反之，则down = up + 1。最后返回两者最大的就好了！
*/
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int res = 0; 
		if (nums.size() == 0 || nums.size() == 1) return res;
		int up = 1;
		int down = 1;
		int n = nums.size();
		for (int i = 1; i < n; i++) {
			if (nums[i] > nums[i - 1]) {
				up = down + 1;
			}
			if (nums[i] < nums[i - 1]) {
				down = up + 1;
			}
		}
		return max(up, down);
	}
};


// 动态规划 （java 代码）
public class Solution {
	public int wiggleMaxLength(int[] nums) {
		if (nums.length < 2)
			return nums.length;
		int[] up = new int[nums.length];
		int[] down = new int[nums.length];
		for (int i = 1; i < nums.length; i++) {
			for (int j = 0; j < i; j++) {
				if (nums[i] > nums[j]) {
					up[i] = Math.max(up[i], down[j] + 1);
				}
				else if (nums[i] < nums[j]) {
					down[i] = Math.max(down[i], up[j] + 1);
				}
			}
		}
		return 1 + Math.max(down[nums.length - 1], up[nums.length - 1]);
	}
}

