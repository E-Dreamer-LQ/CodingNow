// leetcode475-供暖器.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		int num_heaters = heaters.size();
		int num_houses = houses.size();
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int ans = 0;
		//思路：
//对于每座房子，有前后两个供暖器(只有一个供暖器的情况另外判断)，寻找它们之间的较小距离，并与当前最大半径比较更新即可
		for (int i = 0; i < houses.size(); i++)
		{
			int cur = INT_MAX;
			// lower_bound 返回第一个大于等于这个元素的迭代器
			//此时larger就是这座房子右边的供暖器
			//使用*larger来取值,或者heaters[larger-heaters.begin()]
			auto larger = lower_bound(heaters.begin(), heaters.end(), houses[i]);
			if (larger != heaters.end())
			{
				//如果存在的话 那么就计算它们之间的距离
				cur = *larger - houses[i];
			}
			//如果这个元素没有小于最开始的元素 那么意味着它左边也有一个供暖器
			if (larger != heaters.begin())
			{
				//左边供暖器的位置就是当前larger位置-1
				auto smaller = larger - 1;
				//使用*smaller来取得这个值,更新它们之间的较小值
				cur = min(cur, houses[i] - *smaller);
			}
			ans = max(cur, ans);
		}
		return ans;
	}
};
/*
首先将house和heater数组进行排序，然后遍历house，每次遍历时，都去找离house最近的heater，
然后得到最小距离，存为tmp。最后结果就是所有house对应的tmp的最大值！
*/

class Solution {
public:
	int findRadius(vector<int>& houses, vector<int>& heaters) {
		sort(houses.begin(), houses.end());
		sort(heaters.begin(), heaters.end());
		int maxLen = 0;
		for (int i = 0; i < houses.size(); i++) {
			int low = 0, high = heaters.size() - 1;
			int tmp = INT_MAX;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (heaters[mid] == houses[i]) {
					tmp = 0; break;
				}
				else if (heaters[mid] > houses[i]) { // 暖气在房子的右边，应该再往左边找
					tmp = min(tmp, heaters[mid] - houses[i]);
					high = mid - 1;
				}
				else { // 暖气在房子的左边，应该再往右边找
					tmp = min(tmp, houses[i] - heaters[mid]);
					low = mid + 1;
				}
			}
			maxLen = max(tmp, maxLen);
		}
		return maxLen;
	}
};