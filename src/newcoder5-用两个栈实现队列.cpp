// newcoder5-用两个栈实现队列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<stack>
using namespace std; 

class Solution
{
public:
	void push(int node) {  // 整体思路， 先将元素加入到stack1 , 再将元素从1 加入到2 
		stack1.push(node);

	}

	int pop() {
		int res;
		if (stack2.size() > 0) { // 首先判断stack2 栈是否有元素
			res = stack2.top();
			stack2.pop();
		}
		else if (stack1.size() > 0) {
			while (!stack1.empty()) {
				int temp = stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
			res = stack2.top();
			stack2.pop();
		}
		return res;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};
