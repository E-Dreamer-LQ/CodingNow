// leetcode937-重新排列日志文件.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/reorder-data-in-log-files

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 


class Solution {
public:
	vector<string> reorderLogFiles(vector<string>& logs) {
		vector<string> txts,nums;

		//区别数字和字母日志的方法就是最后一个字母是否为数字字符
		for (auto log : logs) {
			int len = log.length();
			if (log[len - 1] >= '0' && log[len - 1] <= '0') {
				nums.push_back(log);
			}
			else {
				txts.push_back(log);
			}
		}

		// 自定义比较器
		auto cmp = [](const string& a, const string& b) {
			string temp1, temp2;
			int s1 = a.find(' '); // 返回的是字符串的下标 （位置）
			int s2 = a.find(' ');
			temp1 = a.substr(s1 + 1, a.size() - s1 - 1); // s.substr(pos, n)的用法， 从pos位置索取n大小的字符串
			temp2 = b.substr(s2 + 1, b.size() - s2 - 1);
			if (temp1 == temp2) {
				return a < b;
			}
			else {
				return temp1 < temp2;
			}
		};

		sort(txts.begin(), txts.end(), cmp);
		for (int i = 0; i < nums.size(); i++) {
			txts.push_back(nums[i]);
		}
		return txts;
	}
};