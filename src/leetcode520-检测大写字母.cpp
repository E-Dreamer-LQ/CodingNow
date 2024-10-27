// leetcode520-检测大写字母.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/detect-capital/
 

/*
单词正确写法： 
全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
*/

#include <iostream>
#include <string>
using namespace std;


// 就他妈的扣细节
class Solution {
public:
	bool detectCapitalUse(string word) {
		int n = word.size();
		if (n == 1) return true;
		bool res;
		char ch = word[0];
		int i = 1;
		if (ch >= 'a' && ch <= 'z') {
			while (word[i] >= 'a' && word[i] <= 'z' && i < n) i++;
			if (i == n) res = true;
			else res = false;
		}
		else {
			if (word[1] >= 'a' && word[1] <= 'z') {
				while (word[i] >= 'a' && word[i] <= 'z' && i < n) i++;
				if (i == n) res = true;
				else res = false;
			}
			if (word[1] >= 'A' && word[1] <= 'Z') {
				while (word[i] >= 'A' && word[i] <= 'Z' && i < n) i++;
				if (i == n) res = true;
				else res = false;
			}
		}
		return res;
	}
};
void main() {
	Solution S;
	string word = "USA";
	bool res = S.detectCapitalUse(word);
	cout << boolalpha << res << endl;

}