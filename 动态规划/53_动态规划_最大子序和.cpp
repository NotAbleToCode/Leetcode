// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:

// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

#include<iostream>
#include<vector>
using namespace std;


// 定义状态f[i]，以i为结尾最大和的连续子数组的和
// 初始状态，f[0]=nums[0]
// 状态转移，f[i]=max(f[i-1]+nums[i],nums[i])，即以i为结尾最大和的连续子数组的和，要么是以i-1为结尾的最大和加该数，要么就是该数
int maxSubArray(vector<int>& nums) {
    int length = nums.size();
    vector<int> max_total(length, 0);
    max_total[0] = nums[0];
    int my_max = max_total[0];
    for(int i=1;i<length;i++){
        max_total[i] = max(nums[i], max_total[i-1]+nums[i]);
    }         
    for(int i=0;i<length;i++){
        my_max = max(my_max, max_total[i]);
    }
    return my_max;
}

int main(){
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums)<<endl;
}
