// leetcode446-数组中重复的数据.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <map>
using namespace std; 

// 方法一
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		vector<int> res;
		multimap<int, int> rb_map{ nums.begin(),nums.end() };
		for (auto num : nums) {
			if (rb_map.count(num) != 1)
				res.push_back(num);
		}
		return res;

	}
};


// 方法二
class Solution2 {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		

	}
};