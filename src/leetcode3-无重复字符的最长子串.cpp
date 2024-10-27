// leetcode3-无重复字符的最长子串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std; 

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> hashmap; 
		int n = s.size(); 
		int left = 0, res = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (hashmap.find(s[i]) != hashmap.end()) {
				left = max(left, hashmap[s[i]] + 1);
			}
			res = max(left, i - left + 1);
			hashmap[s[i]] = i;
		}
		return res; 
	}
};