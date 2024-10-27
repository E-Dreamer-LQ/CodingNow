// newcoder-滑动窗口的最大值.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include<deque>
using namespace std; 


class Solution {
public:
	// 窗口的最大值和最小值的更新结构使用双端队列
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		deque<int> dq_max; 
		vector<int> res; 
		int i = 0;
		int j = 0;
		while (i < num.size()) {
			while (j < num.size()) {
				while (!dq_max.empty() && dq_max.back() < num[j]) {
					dq_max.pop_back(); 
				}
				dq_max.push_back(j); 
				j++; 
			}
			if (dq_max.front() == i) {  // 下标过期弹出
				dq_max.pop_front(); 
			}
			if (size && i + 1 >= size) {
				res.push_back(num[dq_max.front()]);
			}
			i++;
		}
		return res; 
	}
};

class Solution2 {
public:
	vector<int> maxInWindows(const vector<int>& num, unsigned int size)
	{
		vector<int> res;
		deque<int> s;
		for (unsigned int i = 0; i < num.size(); ++i) {
			while (s.size() && num[s.back()] <= num[i])//从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
				s.pop_back();
			while (s.size() && i - s.front() + 1 > size)//当当前窗口移出队首元素所在的位置，即队首元素坐标对应的num不在窗口中，需要弹出
				s.pop_front();
			s.push_back(i);//把每次滑动的num下标加入队列
			if (size && i + 1 >= size)//当滑动窗口首地址i大于等于size时才开始写入窗口最大值
				res.push_back(num[s.front()]);
		}
		return res;
	}
};

void main() {
	Solution S;
	vector<int> num{2,3,4,2,6,2,5,1};
	vector<int> res = S.maxInWindows(num, 3); 
	for (auto it : res) {
		cout << it;
	}

}