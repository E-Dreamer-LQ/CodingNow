// leetcode414-第三大的数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/third-maximum-number/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;




class Solution {
public:
	int thirdMax(vector<int>& nums) {
		//priority_queue<int>  min_heap;
		priority_queue<int, vector<int>,greater<int>> min_heap;  // 建立一个最小堆
		for (int i = 0; i < nums.size(); ++i) {
			if (i < 3) {
				min_heap.push(nums[i]);
			}
			else {
				if (nums[i] > min_heap.top()) {
					min_heap.pop();
					min_heap.push(nums[i]);
				}
			}
		}
		return min_heap.top();
	}
};


// 方法二： map 
class Solution2 {
public:
	int thirdMax(vector<int>& nums) {
		set<int> ss;    // set默认排序规则是从小到大
		for (auto num : nums) {
			ss.insert(num);
			if (ss.size() > 3) {
				ss.erase(*(ss.begin()));
			}
		}
		if (ss.size() < 3)
			return *(ss.rbegin());   //最大的
		else
			return *(ss.begin());    //第三大的
	}
};

void main() {
	vector<int> nums{ 4,5,6,8,1 };
	Solution S;
	Solution2 S2;
	int res = S.thirdMax(nums);
	int res2 = S2.thirdMax(nums);
	cout << res << endl;
	cout << res2 << endl;
}