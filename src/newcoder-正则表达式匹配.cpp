// newcoder-正则表达式匹配.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std; 


class Solution {
public:
	bool match(char* str, char* pattern)
	{
		if (*str == '\0' && *pattern == '\0') { // 两个字符串都为空
			return true;
		}
		if (*str != '\0' && *pattern == '\0') {
			return false;
		}
		// str 空了，pattern 不空一定不能匹配， str 不空，pattern 可能匹配，例如： “a*a*”

		//考虑pattern 的下一个字符为“*” 和 不为"*"


		if (*(pattern + 1) != '*') { // 不为"*" ，直接匹配当前字符
			if (*str == *pattern || (*str != '\0' && *pattern == '.'))
				return match(str + 1, pattern + 1);
			else
				return false;
		}
		else { // 如果是“*”
			if (*str == *pattern || (*str != '\0' && *pattern == '.')) {
				return match(str, pattern + 2) || match(str + 1, pattern);
			}
			else {  //'*' 发挥作用，让上一位次数变为0
				return match(str, pattern + 2);
			}
		}
	}
};


// 2020.5.6 stringstream 的输入输出使用
#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;
int main()
{
	stringstream ostr("ccc");
	cout << ostr.str() << endl;
	ostr.put('d');
	ostr.put('e');
	cout << ostr.str() << endl;
	ostr << "fg";
	string gstr = ostr.str();
	cout << gstr << endl;

	char a;
	while (ostr >> a) {
		cout << a << endl;
	}//可以看到stringstream对象既可以做输入流也可以做输出流
	system("pause");
}