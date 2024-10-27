// string类型转字符创数组(字符串的split).cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://www.jianshu.com/p/5876a9f49413

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std; 


vector<string> split(const string& str, const string& pattern)
{
	vector<string> res;
	if (str == "")
		return res;
	//在字符串末尾也加入分隔符，方便截取最后一段
	string strs = str + pattern;
	size_t pos = strs.find(pattern);

	while (pos != strs.npos)
	{
		string temp = strs.substr(0, pos);
		res.push_back(temp);
		//去掉已分割的字符串,在剩下的字符串中进行分割
		strs = strs.substr(pos + 1, strs.size());
		pos = strs.find(pattern);
	}

	return res;
}


vector<string> split2(const string& str, const string& pattern)
{
	char* strc = new char[strlen(str.c_str()) + 1];
	strcpy(strc, str.c_str());   //string转换成C-string
	vector<string> res;
	char* temp = strtok(strc, pattern.c_str());
	while (temp != NULL)
	{
		res.push_back(string(temp));
		temp = strtok(NULL, pattern.c_str());
	}
	delete[] strc;
	return res;
}


vector<string> split3(const string& str, const char pattern)
{
	vector<string> res;
	stringstream input(str);   //读取str到字符串流中
	string temp;
	//使用getline函数从字符串流中读取,遇到分隔符时停止,和从cin中读取类似
	//注意,getline默认是可以读取空格的
	while (getline(input, temp, pattern))
	{
		res.push_back(temp);
	}
	return res;
}