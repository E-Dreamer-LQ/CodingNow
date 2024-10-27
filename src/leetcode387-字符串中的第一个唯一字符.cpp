// leetcode387-字符串中的第一个唯一字符.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/first-unique-character-in-a-string/

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std; 


class Solution {
public:
	int firstUniqChar(string s) {	
		unordered_map<char, int> hashmap;
		for (int i = 0; i < s.size(); i++) {
			hashmap[s[i]]++;
		}
		for (int j = 0; j < s.size();j++) {
			if (hashmap.find(s[j])->second == 1) {
				return j;
			}
		}
		return -1;
	}
};