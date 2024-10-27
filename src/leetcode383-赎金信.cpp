// leetcode383-赎金信.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/ransom-note

#include <iostream>
#include <string>
using namespace std;

// 和前面子字符串一样

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		if (ransomNote == "") return true;
		int c1 = 0, c2 = 0;
		while (c1 < ransomNote.size() && c2 < magazine.size()) {
			if (ransomNote[c1] == magazine[c2]) {
				c1++;
				c2++;
			}
			else {
				c2++;
			}
		}
		return c1 = ransomNote.length();

	}
};