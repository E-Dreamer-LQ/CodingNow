// newcoder-和为S的两个数字.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;


class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		unordered_map<int, int> hashmap;
		for (auto num : array) {
			hashmap[num]++;
		}
		vector<vector<int>> res;
		vector<int> temp;
		for (auto num : array) {
			if (hashmap.find(sum - num) != hashmap.end()) {
				if (sum - num > num) {
					res.push_back({ num,sum - num });
				}
			}
		}
		auto cmp = [](const vector<int>& a, const vector<int>& b) {
			return a[0] * a[1] < b[0] * b[1];
		};
		sort(res.begin(), res.end(), cmp);
		return res[0];
	}
};



typedef vector<int> vi;
class Solution2 {
public:
	vi FindNumbersWithSum(const vi& a, int sum) {
		vi res;
		int n = a.size();
		int i = 0, j = n - 1;
		while (i < j) {
			if (a[i] + a[j] == sum) {
				res.push_back(a[i]);
				res.push_back(a[j]);
				break;
			}
			while (i < j && a[i] + a[j] > sum) --j;
			while (i < j && a[i] + a[j] < sum) ++i;
		}
		return res;
	}
};

void main() {
	Solution S;
	Solution2 S2;
	vector<int> array{3,4,6,8,9,10};
	int sum = 12;
	vector<int> res = S.FindNumbersWithSum(array, sum);
	vector<int> res2 = S2.FindNumbersWithSum(array, sum);
	for (auto num : res) {
		cout << num;
	}
	cout << endl; 
	for (auto num : res2) {
		cout << num;
	}

}