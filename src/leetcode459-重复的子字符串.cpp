// leetcode459-重复的子字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

// KMP算法

class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		

	}
};



// 方法二: 周期串
bool repeatedSubstringPattern(string s) {
	int len = s.size(), i = 0, t = 0;
	for (t = 1; t <= len / 2; ++t)
	{
		if (len % t) continue;    // 有余数,一定不为周期串
		for (i = t; i < len && s[i % t] == s[i]; ++i);
		if (i == len) return true;
	}
	return false;
}


// 一行代码
/*
一个字符串如果符合要求，则该字符串至少由2个子串组成。例：b b / abc abc

s+s。以后，则该字符串至少由4个子串组成 bb+bb / abcabc+abcabc

截去首尾各一个字符s[1:-1] （注：只截一个是为了判断类似本例，重复子串长度为1的情况。当重复子串长度大于1时，任意截去首尾小于等于重复子字符串长度都可）

由于s+s组成的4个重复子串被破坏了首尾2个，则只剩下中间两个 b bb b。此时在判断中间两个子串组成是否等于s，若是，则成立。

*/
class Solution2 {
public:
	bool repeatedSubstringPattern(string s) {
		string str = s + s;
		str = str.substr(1, str.size() - 2);  // substr 填写的是位置
		if (str.find(s) == -1)   // 没有找到原来字符串
			return false;
		return true;
	}
};


void main() {
	string s = "abcabcabcabc";
	bool res = repeatedSubstringPattern(s);
	cout << boolalpha << res << endl;
}