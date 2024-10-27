// leetcode502-IPO.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// https://leetcode-cn.com/problems/ipo

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
	using Pair = pair<int, int>; // profits , cost
	struct cmpCost{    // 构建小跟堆
		bool operator()(const Pair &a, const Pair &b) {
			return a.second > b.second;
}
	}; 
	struct cmpProfits {  // 构建大根堆
		bool operator() (const Pair& a, const Pair& b) {
			return a.first < b.first;
		}
	};
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		priority_queue<Pair, vector<Pair>,cmpCost> mincost; // 对cost 建立最小堆
		priority_queue<Pair, vector<Pair>, cmpProfits> maxprofits;// 对profits建立最大堆
		// 将cost 的vector数组加入到堆中
		for (int i = 0; i < Capital.size(); i++) {
			mincost.push(make_pair(Profits[i],Capital[i]));
		}
		while (k--) {
			while (!mincost.empty() && mincost.top().second <= W) { // W为初始资金
				maxprofits.push(mincost.top()); // 证明该项目可以被启动
				mincost.pop();

			}
		}
		// 计算最终的收益+初始资金
		if (!maxprofits.empty()) {
			W += maxprofits.top().first;
			maxprofits.pop();
		}
		else {
			return W; //有可能因为资本不足，达不到k次，因此在最大堆为空时，返回结果
		}
		return W;

	}
};

// 来自大神代码，灵活应用pair
class Solution2 {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		using Pair = pair<int, int>;    // cost, profit
		auto cmp1 = [](const Pair& a, const Pair& b) {
			return a.first > b.first;   // minheap of mincost
		};
		auto cmp2 = [](const Pair& a, const Pair& b) {
			return a.second < b.second; // maxheap of maxprofit;
		};   // 注意这种写法用于比较
		priority_queue<Pair, vector<Pair>, decltype(cmp1)> mincost(cmp1);
		priority_queue<Pair, vector<Pair>, decltype(cmp2)> maxprofit(cmp2);
		for (int i = 0; i < Profits.size(); i++) {
			mincost.push(make_pair(Capital[i], Profits[i]));
		}
		while (k--) {
			while (!mincost.empty() && mincost.top().first <= W) {
				maxprofit.push(mincost.top());
				mincost.pop();
			}
			if (maxprofit.empty()) return W;  //有可能因为资本不足，达不到k次，因此在最大堆为空时，返回结果
			W += maxprofit.top().second;
			maxprofit.pop();
		}
		return W;
	}
};


void main() {
	// 要善于这种自定义比较写法
	auto cmp = [](const int& a, const int& b) {
		return a > b;
	};
	vector<int> test{4,6,8,2,1,3,9,7};
	sort(test.begin(), test.end(), cmp);
	for (int i = 0; i < test.size(); i++) {
		cout << test[i];
	}

}