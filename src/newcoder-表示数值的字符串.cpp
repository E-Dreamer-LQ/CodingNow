// newcoder-表示数值的字符串.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std; 
class Solution {
public:
	bool isNumeric(char* str) {
		// 标记符号、小数点、e是否出现过
		bool sign = false, decimal = false, hasE = false;
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == 'e' || str[i] == 'E') {
				if (i == strlen(str) - 1) return false; // e后面一定要接数字
				if (hasE) return false;  // 不能同时存在两个e
				hasE = true;
			}
			else if (str[i] == '+' || str[i] == '-') {
				// 第二次出现+-符号，则必须紧接在e之后
				if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
				// 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
				if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
				sign = true;
			}
			else if (str[i] == '.') {
				// e后面不能接小数点，小数点不能出现两次
				if (hasE || decimal) return false;
				decimal = true;
			}
			else if (str[i] < '0' || str[i] > '9') // 不合法字符
				return false;
		}
		return true;
	}
};





class Solution {
public:
	bool pos_neg = 1, power = 1, point = 1;     // 可用的符号：pos_neg是正负号,power是指数符,point是小数点
	bool isNumber(string s) {
		if (s.empty()) return 0;     // 啥?空的?还不快滚!
		else if (s[0] == '-' || s[0] == '+') {     // 正负号?没事,前面没有正负号和小数点就行
			if (pos_neg && s.length() > 1 && ((s[1] >= '0' && s[1] <= '9') || s[1] == '.')) {
				pos_neg = 0;
				return isNumber(string(s, 1));
			}
			else return 0;
		}
		else if (s[0] == '.') {     // 小数点?没事,前面没有小数点和指数符就行
			if (point && power && s.length() > 1 && s[1] >= '0' && s[1] <= '9')
				return isNumber('0' + s);
			else return 0;
		}
		else if (s[0] == ' ') {     // 空格?没事,空格的尽头递归一遍就行
			int idx = 0;
			while (idx < s.length() && s[idx] == ' ')
				++idx;
			return isNumber(string(s, idx));
		}
		else if (s[0] < '0' || s[0]>'9') // 啥?不是正负不是小数不是空格,还不是数字???还不快滚!
			return 0;
		for (int i = 1; i < s.length(); ++i) {
			if (s[i] >= '0' && s[i] <= '9');     // 数字?下一个
			else if (s[i] == 'e' || s[i] == 'E')  // 指数不允许后面有小数点和另一个指数,但允许正负号
				if (power) {
					power = 0, pos_neg = 1, point = 0;
					return isNumber(string(s, i + 1));
				}
				else return 0;
			else if (s[i] == '.')     // 小数点不允许另一个小数点,而且小数点前面不能有指数
				if (point && power)
					point = 0;
				else return 0;
			else if (s[i] == ' ') {     // 空格不允许出现在串中
				while (i < s.length() && s[i] == ' ') ++i;
				return i == s.length();
			}
			else return 0;
		}
		return 1;
	}
};