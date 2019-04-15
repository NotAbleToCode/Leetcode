// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

// 说明：每次只能向下或者向右移动一步。

// 示例:

// 输入:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// 输出: 7
// 解释: 因为路径 1→3→1→1→1 的总和最小。

// 输入为value矩阵
// 定义状态f(i,j)，到达(i,j)处的路径的数字总和的最小值
// 状态转移f(i,j) = min(f(i-1,j)+value(i,j), f(i,j-1)+value(i,j))
// 状态初始化，第一行和第一列，由于只能向下或向右，则：
// f(0,0) = value(0,0)
// 第一行，f(0,j)=f(0,j-1)+value(0,j)
// 第一列，f(i,0)=f(i-1,0)+value(i,0)

int minPathSum(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int> > f(row);
    for(int i=0;i<row;i++)
        f[i].resize(col);
    f[0][0] = grid[0][0];
    for(int j=1;j<col;j++)
        f[0][j] = f[0][j-1]+grid[0][j];
    for(int i=1;i<row;i++)
        f[i][0] = f[i-1][0]+grid[i][0];
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++)
            f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
    }
    return f[row-1][col-1];
}
