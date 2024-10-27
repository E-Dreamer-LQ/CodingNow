// leetcode219-存在重复元素II.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	bool containsNearbyDuplicate(vector<int>& nums, int k) {
		unordered_map<int, int>map;
		for (int i = 0; i < nums.size(); i++)
		{	
			if (map.count(nums[i]) && (i - map[nums[i]]) <= k) //判断相同的值得索引差值
			{
				return true;          
			}
			map[nums[i]] = i;        //更新nums[i]的索引 ， 对应规则
		}
		return false;
	}
};


// unordered_map 相关： 类似于python中字典, find()函数和end()函数:返回的数据类型均为iterator 
// count()函数：返回要查找的key在map的所有key种的出现次数
// erase()函数: 移除元素， insert()函数：加入元素
