// leetcode473-火柴拼成正方形.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 每根火柴都要用到

class Solution {
public:
	bool allocate(vector<int> nums, int pos, vector<int> sums, int avg) {
		if (pos == -1) {
			return sums[0] == avg && sums[1] == avg && sums[2] == avg;
		}
		// 尝试把火柴放入4个桶中
		for (int i = 0; i < 4; i++) {
			//只有在桶容量足够时才能放入
			if (sums[i] + nums[pos] > avg) continue;  // 该水桶已经装不下了
			// 尝试放入并开始放入下一根火柴
			sums[i] += nums[pos];
			if (allocate(nums, pos - 1, sums, avg)) return true;
			// 放入失败，取出火柴开始下一个桶
			sums[i] -= nums[pos]; // 恢复
		}
		return false;
	}
	bool makesquare(vector<int>& nums) {
		if (nums.size() < 4) return false;
		int sum = 0;
		sort(nums.begin(), nums.end());
		for (auto num : nums) {
			sum += num;
		}
		if (sum % 4 != 0) return false;
		vector<int> tmp(4);
		return allocate(nums, nums.size() - 1, tmp, sum / 4);

	}
};

void main() {
	Solution S;
	vector<int> nums{1,2,2,2,1};
	bool res = S.makesquare(nums);
	cout << boolalpha << res << endl;
}


// DFS， 负数标记已访问数据
class Solution2 {
public:
	bool dfs(vector<int>& nums, int curLen)
	{

		if (curLen == 0) return true;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] > curLen)  return false;
			if (nums[i] > 0)
			{
				nums[i] = -nums[i];     // 置为负数              //标记访问数据
				if (dfs(nums, curLen - abs(nums[i])))
					return true;
				nums[i] = abs(nums[i]);               //恢复
			}
		}
		return false; // 如果最后curlen != 0 
	}

	bool makesquare(vector<int>& nums) {

		if (nums.size() < 4)   return false;
		int sum = 0;
		for (auto num : nums) {
			sum += num;
		}
		if (sum % 4)   return false;                               //余数不为零一定不能构成   

		sort(nums.begin(), nums.end(), greater<int>());           //升序排序，贪心选择长的构建边
		for (int i = 0; i < 3; ++i)                                    //只需判断是否构建出3条长为sum/4的边长
		{
			if (!dfs(nums, sum / 4))    return false;
		}

		return true;
	}
};
