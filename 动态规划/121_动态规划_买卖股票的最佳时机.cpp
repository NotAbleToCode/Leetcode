// 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

// 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。

// 注意你不能在买入股票前卖出股票。

// 示例 1:

// 输入: [7,1,5,3,6,4]
// 输出: 5
// 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
// 示例 2:

// 输入: [7,6,4,3,1]
// 输出: 0
// 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。

// 问题分析
// O(n)时间求每个元素左侧最大值，然后减去该元素，得到的值就是买该元素的最大收益
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int len = prices.size();
    if(len==0){
        return 0;
    }
    vector<int> right_max(len);
    int cur_max = prices[len-1];
    for(int i=len-1;i>=0;i--){
        cur_max = max(cur_max, prices[i]);
        right_max[i] = cur_max;
    }
    int ans = 0;
    for(int i=0;i<len;i++){
        ans = max(ans, right_max[i]-prices[i]);
    }
    return ans;
}

int main(){

}

