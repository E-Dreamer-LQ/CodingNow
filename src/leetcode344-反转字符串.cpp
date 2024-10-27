// leetcode344-反转字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 使用双指针

#include <iostream>
#include <vector> 
using namespace std; 


class Solution {
public:
	void reverseString(vector<char>& s) {
		int l = 0, r = s.size() - 1;
		while (l < r) {
			s[l] ^= s[r];
			s[r] ^= s[l];
			s[l] ^= s[r];
			l++;
			r--;
		}
	}
};