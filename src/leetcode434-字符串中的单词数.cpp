// leetcode434-字符串中的单词数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/number-of-segments-in-a-string

#include <iostream>
#include <string>
using namespace std;


class Solution {
public:
	int countSegments(string s) {
		s += ' ';
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			if (s[i] != ' ' && s[i + 1] == ' ') {
				cnt++;
			}
		}
		return cnt;
	}
};