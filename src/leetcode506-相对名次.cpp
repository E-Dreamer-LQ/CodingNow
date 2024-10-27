// leetcode506-相对名次.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


//分数越高的选手，排名越靠前

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& nums) {
		int len = nums.size();
		vector<string> res(len);
		map<int, int> hashmap;  // key有序, 从小到大
		for (int i = 0; i < nums.size(); i++) {
			hashmap[nums[i]] = i;
		}
		for (auto it : hashmap) {
			if (len == 3) {
				res[it.second] = "Bronze Medal";
				len--;
			}
			else if (len == 2) {
				res[it.second] = "Silver Medal";
				len--;
			}
			else if (len == 1) {
				res[it.second] = "Gold Medal";
			}
			else
				res[it.second] = to_string(len--);
		}
		return res;
	}
};
void main() {
	Solution S;
	vector<string> res;
	vector<int> nums{ 10,3,8,9,4 };
	res = S.findRelativeRanks(nums);
	for (auto s : res) {
		cout << s << endl;
	}

}

