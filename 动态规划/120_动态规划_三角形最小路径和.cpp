// 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

// 例如，给定三角形：

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

// 说明：

// 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。

// 状态定义：f(i,j)，到第i行第j列的最小路径和
// 状态转移：f(i,j)=min(f(i-1, j-1),f(i-1,j))+triangle[i][j]，如果越界，则赋值为无穷大。

int minimumTotal(vector<vector<int>>& triangle) {
    int len = triangle.size();
    if(len==0){
        return triangle[0][0];
    }
    vector<int> f(len+1, 10000000000);
    vector<int> f_temp(len+1, 10000000000);
    f[1] = triangle[0][0];
    for(int i=1;i<len;i++){
        for(int j=1;j<=triangle[i].size();j++)
        {
            f_temp[j] = min(f[j-1],f[j])+triangle[i][j-1];
        }
        f = f_temp;
        for(int i=0;i<=len;i++)
            cout<<f[i]<<" ";
        cout<<endl;
    }
    int ans = f[0];
    for(int i=0;i<len+1;i++){
        ans = min(ans, f[i]);
    }
    return ans;
}