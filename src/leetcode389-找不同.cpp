// leetcode389-找不同.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/find-the-difference
 
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:   
	char findTheDifference(string s, string t) {   
		char res;
		int flag = 1;
		sort(s.begin(), s.end());
		sort(t.begin(), t.begin());
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != t[i]) {
				flag = 0;
				return t[i];
			}
		}
		if (flag == 1)
			return t.back();
	}
};


void main() {
	Solution S;
	string s = "abcd";
	string t = "abcde";
	char res = S.findTheDifference(s, t);
	cout << res << endl;
}
