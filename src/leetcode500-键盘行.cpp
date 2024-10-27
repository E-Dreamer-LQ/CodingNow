// leetcode500-键盘行.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/keyboard-row/

#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;


class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> temp;
		vector<string> res;
		temp.push_back("qwertyuiopQWERTYUIOP");
		temp.push_back("ASDFGHJKLasdfghjkl");
		temp.push_back("zxcvbnmZXCVBNM");
		set<char> rb_map;
		bool flag = false; 
		for (auto str : temp) {
			for (auto s : str) {
				rb_map.insert(s);
			}
			for (auto word : words) {
				for (auto w: word) {
					if (rb_map.count(w)) {
						flag = true; 
						continue;
					}
					else{
						flag = false;
						break;
					}
				}
				if (flag) {
					res.push_back(word); 
				}
			}
			rb_map.clear();
		}
		return res;

	}
};


// 方法二： 不用栈，直接用string.find()


void main() {
	Solution S;
	vector<string> words{ "Hello", "Alaska", "Dad", "Peace" };
	vector<string> res;
	res = S.findWords(words);
	for (auto s : res) {
		cout << s << endl;
	}

}