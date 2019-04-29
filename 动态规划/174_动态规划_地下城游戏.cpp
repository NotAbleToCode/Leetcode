// 一些恶魔抓住了公主（P）并将她关在了地下城的右下角。地下城是由 M x N 个房间组成的二维网格。我们英勇的骑士（K）最初被安置在左上角的房间里，他必须穿过地下城并通过对抗恶魔来拯救公主。

// 骑士的初始健康点数为一个正整数。如果他的健康点数在某一时刻降至 0 或以下，他会立即死亡。

// 有些房间由恶魔守卫，因此骑士在进入这些房间时会失去健康点数（若房间里的值为负整数，则表示骑士将损失健康点数）；其他房间要么是空的（房间里的值为 0），要么包含增加骑士健康点数的魔法球（若房间里的值为正整数，则表示骑士将增加健康点数）。

// 为了尽快到达公主，骑士决定每次只向右或向下移动一步。

// 定义状态f(i,j,0),f(i,j,1)，到(i,j)处所需的最小初始生命值数和最优路径上的点数加和
// 
// 状态转移
// 若d[i][j]>=0
//  若f(i-1,j,0)>f(i,j-1,0)，则f(i,j,0)=f(i-1,j,0),f(i,j,1)=f(i-1,j,1)+d[i][j]，否则，类似
// 反之
//  从上方下来的最小初始生命点数
//  temp1 = (f1[i-1][j]+f2[i-1][j]+d[i][j]>0)?f1[i-1][j]:(f1[i-1][j]-f1[i-1][j]-f2[i-1][j]-d[i][j]+1)
//  从左方来的最小初始生命点数
//  temp2 = (f2[i][j-1]+d[i][j]>0)?f1[i][j-1]:(f1[i][j-1]-f2[i][j-1]-d[i][j])
//  if temp1 > temp2:f1[i][j]=temp2, f2[i][j]=f2[i-1][j]+d[i][j]


// 正序求解
// 如果我们定义f(i,j)，为从原点，到(i,j)所需的最小初始化生命值，那么状态转移方程很难得到。
// 因为，考虑f(i-1,j)，f(i,j-1)。f(i,j)和它们并不是直接相关的。事实上，如何转移还和到(i-1,j)和到(i,j-1)的收益有关。都考虑的话很很麻烦。
// 逆序求解
// 定义f(i,j)为(i,j)到终点所需的最小初始化生命值。
// 那么，f(i,j)和f(i+1,j),f(i,j+1)是直接相关的。
#include<iostream>
#include<vector>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int m=dungeon.size(),n=dungeon[0].size();
    vector<vector<int> > dp(m,vector<int> (n,0));
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i==m-1 && j==n-1) dp[i][j]=max(1,1-dungeon[i][j]);
            else if(i==m-1) dp[i][j]=max(1,dp[i][j+1]-dungeon[i][j]);
            else if(j==n-1) dp[i][j]=max(1,dp[i+1][j]-dungeon[i][j]);
            else dp[i][j]=max(1,min(dp[i+1][j],dp[i][j+1])-dungeon[i][j]);
        }
    }
    int res=dp[0][0];
    return res;
}


int main(){
    vector<vector<int> >test1(15, vector<int>(1));
    test1={{3},{49},{38},{30},{-93},{-99},{13},{10},{6},{-77},{-83},{-76},{24},{-40},{-73}};
    vector<vector<int> >test2(1, vector<int>(15));
    test2={{3,49,38,30,-93,-99,13,10,6,-77,-83,-76,24,-40,-73}};
    vector<vector<int> >test3(3, vector<int>(3));
    test3={{1,-3,3},{0,-2,0},{-3,-3,-3}};
    cout<<calculateMinimumHP(test3)<<endl;
}