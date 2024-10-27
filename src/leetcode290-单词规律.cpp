// leetcode290-单词规律.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//  博客： https://blog.csdn.net/qjh5606/article/details/81453669

#include <iostream>
#include <unordered_map>
#include<sstream>      
using namespace std; 

class Solution {
public:
	bool wordPattern(string pattern, string str) {
		unordered_map<char, int> charmap;
		unordered_map<string, int> strmap;
		int i = 0;
		istringstream is(str);
		string s = "";
		while (is >> s) {
			if (i == pattern.size()) 
				return false;  // 长度不一样，失败
			if (strmap[s] != charmap[pattern[i]])  
				return false;
			else
				strmap[s] = charmap[pattern[i]] = i + 1; // 加入到两个哈希表形成映射
			i++;
		}
		return i == pattern.size();
	}
};

void  main(){
	Solution s;
	string p = "abba";
	string str = "dog cat cat dog"; 
	bool result = s.wordPattern(p, str);
	cout << boolalpha <<  result << endl;
}
