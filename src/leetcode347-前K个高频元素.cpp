// leetcode347-前K个高频元素.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// 

#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
#include <unordered_map>
#include <queue>
using namespace std;



// 方法一
class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector <int> res;
		// 统计每个元素出现的个数
		map <int, int> hash;
		for (auto num : nums) {
			hash[num]++;
		}
		vector <pair<int,int>> hashv(hash.begin(), hash.end());//因为sort只能对有序容器排序，所以将map转成vector
		sort(hashv.begin(), hashv.end(), comp); // comp 函数可以改变排序规则
		int i = 0;
		while (i < k) {
			res.push_back(hashv[i++].first);
		}
		return res;
	}

	bool comp(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};



// 方法二： 使用最小堆 
typedef pair<int, int> IIPair;

struct cmp {
	bool operator()(const IIPair& left, const IIPair& right) const
	{
		return left.second > right.second;
	}
};

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> mp;
	for (auto i : nums) {
		mp[i]++;
	}

	priority_queue<IIPair, vector<IIPair>, cmp> q; // 创建一个小顶堆（优先队列）， 默认是创建大顶堆

	for (auto item : mp) {
		if (q.size() < k) {
			q.push(item);
		}  // 压入k个元素
		else if (item.second > q.top().second) {
			q.pop();
			q.push(item);
		}
		// 新的元素频次小于堆顶元素频次的元素不处理，如果大于则将堆顶弹出并且将新元素如堆
	}

	vector<int> ret(q.size(), 0);

	while (!q.empty()) {
		ret[q.size() - 1] = q.top().first;
		q.pop();
	}

	return ret;
}
