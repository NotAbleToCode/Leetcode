// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

// 示例 1:

// 输入: [1,2,3,1]
// 输出: 4
// 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
//      偷窃到的最高金额 = 1 + 3 = 4 。
// 示例 2:

// 输入: [2,7,9,3,1]
// 输出: 12
// 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
//      偷窃到的最高金额 = 2 + 9 + 1 = 12 。

#include<iostream>
#include<vector>
using namespace std;

// 状态f[i]，最后一个偷第i个房屋能获得的最大收益
// 状态转移f[i] = max(f[i-k](k>=2))+nums[i]
// 注意这里由于依赖的状态很少，可以不用初始化数组，节约空间
// 注意状态的定义，如果定义为前i个房屋能获得的最大收益，那么状态转移方程会很麻烦。

int rob(vector<int>& nums) {
    int len = nums.size();
    if(len==0){
        return 0;
    }
    if(len==1){
        return nums[0];
    }
    if(len==2){
        return max(nums[0], nums[1]);
    }
    int temp1 = nums[0];
    int temp2 = nums[1];
    int cur_max = 0;
    int ans = max(temp1, temp2);
    for(int i=2;i<len;i++){
        cur_max = temp1 + nums[i];
        ans = max(ans, cur_max);
        temp1 = max(temp1, temp2);
        temp2 = cur_max;
    }
    return ans;
}

int main(){
    vector<int> test{1,3,1};
    cout<<rob(test)<<endl;
}
