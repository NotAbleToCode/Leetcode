// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
// 问总共有多少条不同的路径？

// 一共走(m-1)+(n-1)步，从这些步里选n-1个
// 故有C_((m-1)+(n-1))^(n-1)

#include<iostream>
using namespace std;

int uniquePaths(int m, int n) {
    int a = min(m, n)-1;
    int b = (m-1)+(n-1);
    long long num = 1;
    long long den = 1;
    for(int i=0;i<a;i++)
        num *= (b-i);
    for(int i=1;i<=a;i++)
        den *= i;
    return int(num/den);
}

int main(){
    cout<<uniquePaths(7,3)<<endl;
}