// leetcode345-反转字符串的元音字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// c++中set 的使用：  https://blog.csdn.net/byn12345/article/details/79523516

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std; 

class Solution {
public:
	string reverseVowels(string s) {
		set<char> a;
		a.insert('a');
		a.insert('e');
		a.insert('i');
		a.insert('o');
		a.insert('u');
		a.insert('A');
		a.insert('E');
		a.insert('I');
		a.insert('O');
		a.insert('U');
		int l = 0, r = s.size() - 1;
		while (l < r) {
			if (a.find(s[l]) == a.end()) l++;
			if (a.find(s[r]) == a.end()) r--;
			s[l] ^= s[r];
			s[r] ^= s[l];
			s[l] ^= s[r];
		}
		return s;
	}
};


