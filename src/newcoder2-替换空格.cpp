// newcoder2-替换空格.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

// 直接遍历
class Solution {
public:
	void replaceSpace(char* str, int length) {
		for(int i =0;i< length; i++)


	}
};



class Solution2 {
public:
	void replaceSpace(char* str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ')
				count++;
		}
		for (int i = length - 1; i >= 0; i--) {
			if (str[i] != ' ') {
				str[i + 2 * count] = str[i];
			}
			else {
				count--;
				str[i + 2 * count] = '%';
				str[i + 2 * count + 1] = '2';
				str[i + 2 * count + 2] = '0';
			}
		}
	}
};


class Solution3 {
public:
	void replaceSpace(char* str, int length) {
		//遍历一边字符串找出空格的数量
		if (str == NULL || length < 0)
			return;
		int i = 0;
		int oldnumber = 0;//记录以前的长度
		int replacenumber = 0;//记录空格的数量
		while (str[i] != '\0')
		{
			oldnumber++;
			if (str[i] == ' ')
			{
				replacenumber++;
			}
			i++;
		}
		int newlength = oldnumber + replacenumber * 2;//插入后的长度
		if (newlength > length)//如果计算后的长度大于总长度就无法插入
			return;
		int pOldlength = oldnumber; //注意不要减一因为隐藏个‘\0’也要算里
		int pNewlength = newlength;
		while (pOldlength >= 0 && pNewlength > pOldlength)//放字符
		{
			if (str[pOldlength] == ' ') //碰到空格就替换
			{
				str[pNewlength--] = '0';
				str[pNewlength--] = '2';
				str[pNewlength--] = '%';

			}
			else //不是空格就把pOldlength指向的字符装入pNewlength指向的位置
			{
				str[pNewlength--] = str[pOldlength];

			}
			pOldlength--; //不管是if还是elsr都要把pOldlength前移

		}
	}
};

