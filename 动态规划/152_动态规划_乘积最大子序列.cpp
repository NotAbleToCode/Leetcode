// 给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。

// 示例 1:

// 输入: [2,3,-2,4]
// 输出: 6
// 解释: 子数组 [2,3] 有最大乘积 6。
// 示例 2:

// 输入: [-2,0,-1]
// 输出: 0
// 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。

// 状态f[i][0]，f[i][1]，分别为以i为乘积结尾的最小子序列的最小值，最大子序列的最大值
// 状态转移
// 如果nums[i]>0，则f[i][0]=f[i-1][0]*nums[i]，f[i][1]= f[i-1][1]==0?nums[i]:f[i-1][1]*nums[i]
// 如果nums[i]<0，则f[i][0]=f[i-1][1]==0?nums[i]:f[i-1][1]*nums[i]，f[i][1]=f[i-1][0]*nums[i]
// 如果nums[i]==0，则f[i][0]=f[i][1]=0

int maxProduct(vector<int>& nums) {
    int len = nums.size();
    vector<vector<int> > f(len, vector<int>(2));
    f[0][0] = nums[0];
    f[0][1] = nums[0];
    int ans = nums[0];
    for(int i=1;i<len;i++){
        if(nums[i]>0){
            f[i][0] = min(nums[i], f[i-1][0]*nums[i]);
            f[i][1] = max(nums[i], f[i-1][1]==0?nums[i]:f[i-1][1]*nums[i]);
        }
        else if(nums[i]<0){
            f[i][0] = min(nums[i], f[i-1][1]==0?nums[i]:f[i-1][1]*nums[i]);
            f[i][1] = max(nums[i], f[i-1][0]*nums[i]);
        }
        else{
            f[i][0]=0;
            f[i][1]=0;
        }
        ans = max(ans, f[i][1]);
    }
    return ans;
}


