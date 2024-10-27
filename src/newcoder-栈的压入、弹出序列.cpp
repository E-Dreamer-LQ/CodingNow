// newcoder-栈的压入、弹出序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std; 

/*
【思路】借用一个辅助的栈，遍历压栈顺序，先讲第一个放入栈中，这里是1，
然后判断栈顶元素是不是出栈顺序的第一个元素，这里是4，很显然1≠4，
所以我们继续压栈，直到相等以后开始出栈，出栈一个元素，则将出栈顺序向后移动一位，
直到不相等，这样循环等压栈顺序遍历完成，如果辅助栈还不为空，
说明弹出序列不是该栈的弹出顺序。

举例：
入栈1,2,3,4,5
出栈4,5,3,2,1
首先1入辅助栈，此时栈顶1≠4，继续入栈2
此时栈顶2≠4，继续入栈3
此时栈顶3≠4，继续入栈4
此时栈顶4＝4，出栈4，弹出序列向后一位，此时为5，,辅助栈里面是1,2,3
此时栈顶3≠5，继续入栈5
此时栈顶5=5，出栈5,弹出序列向后一位，此时为3，,辅助栈里面是1,2,3
….
依次执行，最后辅助栈为空。如果不为空说明弹出序列不是该栈的弹出顺序。
*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) { // 12345    45321
		stack<int> sta;
		int index = 0;
		for (int i = 0; i < popV.size(); ++i) {
			while (sta.empty() || sta.top() != popV[i]) {  
				sta.push(pushV[index++]); // sta压入元素，index+1 
				if (index > pushV.size()) { // 压入的元素大于出栈的元素直接返回
					return false; 
				}
			}
			sta.pop();  // 相等了，辅助栈弹出
		}
		if (sta.empty()) {  // 判断辅助栈是否为空
			return true;
		}
		else {
			return false;    
		}
	}
};



/*
python
链接：https://www.nowcoder.com/questionTerminal/d77d11405cc7470d82554cb392585106
来源：牛客网

# -*- coding:utf-8 -*-
class Solution:

	def IsPopOrder(self, pushV, popV):
		# stack中存入pushV中取出的数据
		stack=[]
		while popV:
			# 如果第一个元素相等，直接都弹出，根本不用压入stack
			if pushV and popV[0]==pushV[0]:
				popV.pop(0)
				pushV.pop(0)
			#如果stack的最后一个元素与popV中第一个元素相等，将两个元素都弹出
			elif stack and stack[-1]==popV[0]:
				stack.pop()
				popV.pop(0)
			# 如果pushV中有数据，压入stack
			elif pushV:
				stack.append(pushV.pop(0))
			# 上面情况都不满足，直接返回false。
			else:
				return False
		return True

*/