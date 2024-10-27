// leetcode384-打乱数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/shuffle-an-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h> 

#include <random>



using namespace std;


class Solution {
public:

	vector<int> ori_nums;
	vector<int> cur_nums;
	int N; 

	Solution(vector<int>& nums) {
		ori_nums = nums;
		cur_nums = nums;
		N = ori_nums.size();
		
	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return ori_nums; 

	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		
		for (int i = 0; i < cur_nums.size(); i++) {
			int r = rand() % (i + 1);
			swap(cur_nums[r], cur_nums[i]); 
		}
		
		return cur_nums;
		
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

void main() {

	
}