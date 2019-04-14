// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

// 状态f(i,j)，走到第i行第j列的方法数
// 状态转移，由于只能向下或向右走，因此(i,j)只能由(i-1,j)和(i,j-1)到达。
// 因此，若(i,j)为石头，f(i,j)为0，否则f(i,j)=f(i-1,j)+f(i,j-1)
// 初始化状态，初始化矩阵的第一行和第一列即可，第一行，直到遇到石头前，都是1，遇到石头，break，石头和石头后面的为0

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    int row = obstacleGrid.size();
    int col = obstacleGrid[0].size();
    vector<vector<long long> > f(row);
    for(int i=0;i<row;i++)
        f[i].resize(col,0);
    // 初始化行和列
    int count = 0;
    while(count<col){
        if(obstacleGrid[0][count]==1)
            break;
        f[0][count] = 1;
        count += 1;
    }
    count = 0;
    while(count<row){
        if(obstacleGrid[count][0]==1)
            break;
        f[count][0] = 1;
        count += 1;
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++)
            if(obstacleGrid[i][j]!=1)
                f[i][j] = f[i-1][j] + f[i][j-1];
    }
    return f[row-1][col-1];
}