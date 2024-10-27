// leetcode168-Excel表列名称.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/excel-sheet-column-title

#include <iostream>
#include<string>
using namespace std;


 // 26进制问题
class Solution {
public:
	string convertToTitle(int n) {
		char ch = 'A';
		string res = "";
		while (n != 0) {
			n--;
			res += (ch + n % 26);
			n /= 26;
		}
		reverse(res.begin(), res.end());
		return res;
	}
};


// 方法二
class Solution {
public:
	string convertToTitle(int n) {
		char ch = 'A';
		string res = "";
		int temp = 0;
		while (n != 0) {
			n--; // 因为1+A的ascii码 =B
			int temp = n % 26;
			res = (char)(temp + "A") + res;
			n = n / 26; 
		}
		return res;
	}
};


