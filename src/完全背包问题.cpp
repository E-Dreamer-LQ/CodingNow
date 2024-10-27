// 完全背包问题    动态规划

#include <iostream>
#include <algorithm>
using namespace std;

int full_bag_question(vector<int>& W, vector<int> V, int value){
	int m = W.size();  // dp[i][j] : 代表前i个物品在背包剩余量j 下的的最大价值
	vector<vector<int>(m,0)>> dp(m);
	dp[0][0] = 0;
	for ( int i= 1; i < W.size(); ++i){
		for (int j = 1; j < value;++j)
		{
			if (j<W[i]){
				dp[i][j] = dp[i-1][j]; // 物品i没有装
			}
			else{
				for (int k = 1; i < j/W[i] + 1; k++){  // 一个物品可以多次装入袋中
					dp[i][j] = max(dp[i-1][j-k*W[i]] + k*V[i], dp[i-1][j]);
			}
		}
		}
	}

}