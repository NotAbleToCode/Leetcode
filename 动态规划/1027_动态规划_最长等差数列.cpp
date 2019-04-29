// 给定一个整数数组 A，返回 A 中最长等差子序列的长度。
// 回想一下，A 的子序列是列表 A[i_1], A[i_2], ..., A[i_k] 其中 0 <= i_1 < i_2 < ... < i_k <= A.length - 1。并且如果 B[i+1] - B[i]( 0 <= i < B.length - 1) 的值都相同，那么序列 B 是等差的。

// 示例 1：
// 输入：[3,6,9,12]
// 输出：4
// 解释： 
// 整个数组是公差为 3 的等差数列。
// 示例 2：
// 输入：[9,4,7,2,10]
// 输出：3
// 解释：
// 最长的等差子序列是 [4,7,10]。
// 示例 3：
// 输入：[20,1,15,3,10,5,8]
// 输出：4
// 解释：
// 最长的等差子序列是 [20,15,10,5]。

// 定义状态
// f(a,b,c)，以下标a结尾的，公差为b的，等差数列的最长长度为c
// 状态转移，

#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<pair>
using namespace std;

int longestArithSeqLength(vector<int>& A) {
    // 以a为结尾的，差为b的，等差数列的长度
    int my_max = 0;
    unordered_map<pair<int, int>, int> f;
    for(int i=0;i<A.size();i++){
        for(int j=i+1;j<A.size();j++){
            if(f[pair<int,int> (i,A[j]-A[i])]==0){
                f[pair<int,int> (j,A[j]-A[i])] = 2;
            }
            else{
                f[pair<int,int> (j,A[j]-A[i])] = f[pair<int,int> (i,A[j]-A[i])] + 1;
            }
            my_max = max(my_max, f[pair<int,int> (j,A[j]-A[i])]);
        }
    }        
    return my_max;
}

int main(){
    map<pair<int, int>, int> temp;
    temp[pair<int,int> (3,3)]=3;
    cout<<temp[pair<int,int> (2,3)]<<endl;
}

// 附：
// 1)
//  注意map和unordered_map的区别。
//  map是红黑树实现的，unorder_map是哈希表实现的。单就查询而言，后者比前者快。
//  C++里面，unorder_map不能哈希pair对象，只能哈希整数，浮点数，字符串等常见的对象。map则不然。
//  此题用unorder_map速度会更快。若用unorder_map，则应定义unorder_map<int, unorder_map<int, int>>
// 2)
//  该题的动态规划和普通的动态规划略有不同。
//  普通的动态规划一般是以状态转移方程为依据，先初始化状态，再遍历。即根据状态转移方程定遍历顺序。
//  但该题是根据遍历顺序来转移状态的。这种类型的，状态一般不放在数组里，因为很多状态用不到。常用哈希表实现。