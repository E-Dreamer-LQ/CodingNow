// LeetCode268-缺失数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std; 

//异或运算满足结合律： 0^a = a , a^a = 0 

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = 0,i;
		for (i=0 ; i < nums.size(); i++)
		{
			res ^= nums[i];
			res ^= i;
		}
		return res ^ i;
	}
};
