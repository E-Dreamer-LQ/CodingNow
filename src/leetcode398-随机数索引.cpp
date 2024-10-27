// leetcode398-随机数索引.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  https://leetcode-cn.com/problems/random-pick-index

// 随机输出给定的数字的索引 , 返回的是位置
 
#include <iostream>
#include <vector>
using namespace std; 

// 暴力法
class Solution {
public:
	vector<int> Ori_nums; 
	Solution(vector<int>& nums) {
		Ori_nums = nums;
	}

	int pick(int target) {
		int size = Ori_nums.size();
		vector<int> res; 
		for (int i = 0; i < size; i++) {
			if (target == Ori_nums[i]) {
				res.push_back(i);
			}
		}
		int random = rand() % (res.size()-1);
		cout << random << endl;
		return res[random];
	}
	// 来自别人：蓄水池采样
	//假设当前正要读取第n个数据，则我们以1/n的概率留下该数据，否则留下前n-1个数据中的一个。
	int pick2(int target) {
		int n = 0;
		int index = 0;
		for (int i = 0; i < Ori_nums.size(); i++)
			if (Ori_nums[i] == target) {
				n++; 
				//我们以1/n的概率留下该数据
				if (rand() % n == 0)  // 概率构造
					index = i;
			}
		return index;
	}
};


void main() {
	vector<int> nums{ 1,2,3,3,3 };
	Solution* S = new Solution(nums);
	int target = 3;
	int param_1 = S->pick(target);
	cout << param_1 << endl;
	cout << S->pick2(target) << endl;

 }