// leetcode125-验证回文串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std; 

class Solution {
public:
	bool isPalindrome(string s) {
		if (s.size() == 0) return true;
		string temp = "";
		for (int i = 0; i < s.size(); i++) {
			if (s[i] < 'a' || s[i] > 'z' || s[i] < 'A' || s[i] >'Z') {
				continue;
			}
			else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <='Z')) {
				temp += tolower(s[i]);
			}
			else {
				temp += s[i];
			}
		}
		for (int i = 0, j = temp.size() - 1; i < temp.size(), j >= 0; i++, j--) {
			cout << temp[j]; 
			if (temp[i] != temp[j]) {
				return false;
			}
		}
	}
};

class Solution2 {
public:
	bool isPalindrome(string s) {
		for (int left = 0, right = s.size() - 1; left < right; left++, right--)      //定义双指针
		{
			while (!isalnum(s[left]) && left < right)   left++;       //直到s[left]为字母或数字,判断字符变量c是否为字母或数字，若是则返回非零，否则返回零
			while (!isalnum(s[right]) && left < right)   right--;       //直到s[right]为字母或数字
			if (toupper(s[left]) != toupper(s[right]))     //toupper将小写字母变为大写，如果是数字则不变
				return false;
		}
		return true;
	}
};



void main() {
	Solution S; 
	Solution2 S2; 
	string s = "race a car";
	bool res = S.isPalindrome(s); 
	bool res2 = S2.isPalindrome(s); 
	cout << boolalpha << res << endl;
	cout << boolalpha << res2 << endl; 

}
