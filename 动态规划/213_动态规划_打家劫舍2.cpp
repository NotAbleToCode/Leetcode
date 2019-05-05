// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

// 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

// 示例 1:

// 输入: [2,3,2]
// 输出: 3
// 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
// 示例 2:

// 输入: [1,2,3,1]
// 输出: 4
// 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
//      偷窃到的最高金额 = 1 + 3 = 4 。

// 可以分成两个情况来考虑：偷第一家和不偷第一家
// 偷第一家，那么只需考虑第一个到第n-1个住户
// 不偷第一家，只需考虑第二个到第n个住户
// 对于以上两种情况，分别用198的思路来求解，得到的两个最大值再取最大即可

#include<iostream>
#include<vector>
using namespace std;

int sub_rob(vector<int>& nums) {
    int len = nums.size();
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

int rob(vector<int>& nums) {
    if(nums.empty()){
        return 0;
    }
    int len = nums.size();
    cout<<len<<endl;
    vector<int> temp(len-1);
    int max1;
    int max2;
    if(len==1){
        return nums[0];
    }
    for(int i=0;i<len-1;i++){
        temp[i] = nums[i];
    }
    max1 = sub_rob(temp);
    for(int i=1;i<len;i++){
        temp[i-1] = nums[i];
    }
    max2 = sub_rob(temp);
    return max(max1, max2);
}


int main(){
    vector<int> test{};
    cout<<rob(test)<<endl;
}