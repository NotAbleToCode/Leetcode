// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 示例 1:

// 输入: [3,3,5,0,0,3,1,4]
// 输出: 6
// 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//      随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
// 示例 2:

// 输入: [1,2,3,4,5]
// 输出: 4
// 解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
//      注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
//      因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 示例 3:

// 输入: [7,6,4,3,1] 
// 输出: 0 
// 解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。

// 问题分析
// 首先，求每个元素右侧最大值，得到买入该元素可获得的最大收益数组A。其次，求每个元素左侧最小值，得到卖出该元素可获得的最大收益数组B。
// 于是，问题变为求最大的B[i]+A[j]，其中j>=i
// 那么，求A中每个元素右侧最大值数组C，和B中每个元素左侧最大值数组D，然后求C+D的最大值，即为结果
// 时间复杂度O(n)
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len==0){
        return 0;
    }
    // i时刻买入获得的最大收益
    vector<int> buy_in(len);
    int cur_max = prices[len-1];
    for(int i=len-1;i>=0;i--){
        cur_max = max(cur_max, prices[i]);
        buy_in[i] = cur_max-prices[i];
    }
    // i时刻卖出获得的最大收益
    vector<int> sell_out(len);
    int cur_min = prices[0];
    for(int i=0;i<len;i++){
        cur_min = min(cur_min, prices[i]);
        sell_out[i] = prices[i]-cur_min;
    }
    vector<int> left_max(len);
    vector<int> right_max(len);
    int cur_max_1 = right_max[len-1];
    int cur_max_2 = left_max[0];
    for(int i=0;i<len;i++){
        cur_max_1 = max(cur_max_1, buy_in[len-i-1]);
        right_max[len-i-1] = cur_max_1;
        cur_max_2 = max(cur_max_2, sell_out[i]);
        left_max[i] = cur_max_2;
    }
    int ans = 0;
    for(int i=0;i<len;i++){
        ans = max(ans, left_max[i]+right_max[i]);
    }
    return ans;
}

int main(){
    vector<int> test{3,3,5,0,0,3,1,4};
    cout<<maxProfit(test)<<endl;
}
