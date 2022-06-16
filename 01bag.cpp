//给定一个能装W的包和N个物品，每个物品有重量和价值两个参数，重量为wt[i],价值为val[i]，最多能装多少价值。

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mostValuable(int W, int N, vector<int>& wt, vector<int>& val){
    vector<vector<int> > dp(N + 1, vector<int>(W + 1, 0));
    for(int  i = 1; i <= N; i++){
        for(int w = 1; w <= W; w++){
            if (w - wt[i - 1] < 0){
                dp[i][w] = dp[i - 1][w];
            }else{
                dp[i][w] = max(dp[i-1][w], dp[i - 1][w - wt[i]] + val[i - 1]);

            }
        }//for2
    }//for1
    return dp[N][W];
}//