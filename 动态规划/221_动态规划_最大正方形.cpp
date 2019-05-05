// 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。

// 示例:

// 输入: 

// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0

// 输出: 4


// 状态定义
// 有三个状态，假定矩阵为M*N，每个状态的矩阵也都是M*N大小
// f1(i,j)，记录(i,j)位置向左上角能扩展的最大位数。能扩展一位，说明以(i,j)为右下角的正方形面积最大值为1。
// f2(i,j)，记录(i,j)位置向上能扩展的最大位数（即向上的最长的连续1的长度）
// f3(i,j)，记录(i,j)位置向左能扩展的最大位数
// 状态转移
// 若matrix[i][j]==0，则f1(i,j)=0，f2(i,j)=0，f3(i,j)=0,
// 若matrix[i][j]==1，则f1(i,j)=min(f1(i-1,j-1), f2(i-1,j), f3(i,j-1))+1，f2(i,j)=f2(i-1,j)+1，f3(i,j)=f3(i,j-1)+1
// 状态初始化及遍历顺序
// 只需初始化第一行和第一列，遍历顺序从第二行第二列开始遍历
// 最终答案
// f1中最大值的平方即是最终答案
// 时间复杂度O(n^2)

#include<iostream>
#include<vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int ans = 0;
    if(row==0){
        return 0;
    }
    int col = matrix[0].size();
    if(col==0){
        return 0;
    }
    vector<vector<int> > f1(row, vector<int>(col));
    vector<vector<int> > f2(row, vector<int>(col));
    vector<vector<int> > f3(row, vector<int>(col));
    f1[0][0] = (matrix[0][0] == '1');
    f2[0][0] = (matrix[0][0] == '1');
    f3[0][0] = (matrix[0][0] == '1');
    ans = max(ans, f1[0][0]);
    for(int i=1;i<col;i++){
        f1[0][i] = (matrix[0][i] == '1');
        f2[0][i] = (matrix[0][i] == '1');
        f3[0][i] = (matrix[0][i] == '1')?(f3[0][i-1]+1):0;
        ans = max(f1[0][i], ans);
    }
    for(int i=1;i<row;i++){
        f1[i][0] = (matrix[i][0] == '1');
        f2[i][0] = (matrix[i][0] == '1')?(f2[i-1][0]+1):0;
        f3[i][0] = (matrix[i][0] == '1');
        ans = max(f1[i][0], ans);
    }
    for(int i=1;i<row;i++){
        for(int q=1;q<col;q++){
            if(matrix[i][q]=='0'){
                f1[i][q] = 0;
                f2[i][q] = 0;
                f3[i][q] = 0;
            }
            else{
                f1[i][q] = min(f1[i-1][q-1], min(f2[i-1][q], f3[i][q-1]))+1;
                f2[i][q] = f2[i-1][q] + 1;
                f3[i][q] = f3[i][q-1] + 1;
                ans = max(ans, f1[i][q]);
            }
        }
    }
    return ans*ans;
}

int main(){
    vector<vector<char> >test{{'0','0','0'},{'0','0','0'},{'0','0','0'},{'0','0','0'}};
    cout<<maximalSquare(test)<<endl;
}