// leetcode-逆波特兰式的值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std; 


class Solution {
public:
	int evalRPN(vector<string>& tokens)
	{
		stack<int> stack;
		int a, b;
		for (auto e : tokens)
		{
			if (e == "+")
			{
				int a = stack.top(); stack.pop();
				int b = stack.top(); stack.pop();
				stack.push(b + a);
			}
			else if (e == "-")
			{
				int a = stack.top(); stack.pop();
				int b = stack.top(); stack.pop();
				stack.push(b - a);
			}
			else if (e == "*")
			{
				int a = stack.top(); stack.pop();
				int b = stack.top(); stack.pop();
				stack.push(b * a);
			}
			else if (e == "/")
			{
				int a = stack.top(); stack.pop();
				int b = stack.top(); stack.pop();
				stack.push(b / a);
			}
			else
				stack.push(atoi(e.c_str()));
		}
		return stack.top();

	}
};
