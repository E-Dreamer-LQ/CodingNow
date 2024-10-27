// leetcode409-最长回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  https://leetcode-cn.com/problems/longest-palindrome/

#include <iostream>
#include <string>
#include <map>
using namespace  std; 

// 方法一： 哈希表
class Solution {
public:
	int longestPalindrome(string s) {
		if (s.size() == 0) return 0;
		map<char, int> hashmap;
		for (auto str : s) {
			hashmap[str]++;
		}
		int count = 0;
		for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
			if (it->second%2 == 0) {
				count += it->second;
			}
			else {
				count += it->second - 1;   // 如果有奇数个的，就变成偶数个的
			}
		}
		if (count < s.size()) {      // 如果不是全部都是偶数个的， 则结果中只能有一个奇数个
			count += 1;      
		}
		return count;
	}
};


// 方法二： 巧用flag
/*
class Solution :
	def longestPalindrome(self, s: str) -> int :
	a = set(s)
	b = list(a)
	oddc = 0
	flag = 0
	for i in range(len(b)) :
		c = s.count(b[i])
		if c % 2 != 0 :
			oddc += 1
			flag = 1
	l = len(s) - (oddc - flag)
	return l

*/

