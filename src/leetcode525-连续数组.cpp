// leetcode525-连续数组.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std; 

// 方法一： 将0 -> -1 
class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		unordered_map <int, int> hashmap;  //HashMap  来保存所有的(index, count) 对
		int cur = 0;
		int res = 0;
		hashmap[0] = -1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]) {
				cur += 1;
			}
			else {
				cur += -1;
			}
			if (hashmap.find(-1) != hashmap.end()) {
				res = max(res, i - hashmap[cur]);
			}
			else {
				hashmap[cur] = i;// 覆盖 
			}
		}
		return res;

	}
};

