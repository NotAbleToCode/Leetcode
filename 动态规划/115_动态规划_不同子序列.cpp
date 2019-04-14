// 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
// 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
// （例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）


// 问题分析
// 在解决72的时候，也曾想过计算S的子序列中出现的T的最长连续子序列。和该题倒是有些相似。
// 定义状态，f(i,j)，S[0:i]中子序列T[0:j]出现的个数。
// 状态转移
// 若S[i]==T[j]，若S[i]用于和T[j]匹配，则S[0:i]中子序列T[0:j]出现的个数，就是S[0:i-1]中子序列T[0:j-1]出现的个数，若S[i]不用于和T[j]匹配，则就是S[0:i-1]中子序列T[0:j]出现的个数
// 若S[i]!=T[j]，则S[i]不用于和T[j]匹配，故为S[0:i-1]中子序列T[0:j]出现的个数
// 综上，可得f(i,j)=f(i-1,j-1)+f(i-1,j) if S[i]==T[j] else f(i-1,j)
// 初始化
// 根据状态转移，可以知道，每个状态依赖于左上角和正上方的状态。只需要初始化第一行的状态即可。
// f(0,0)=1 if S[0]==T[0] else 0，f(0,j)=0，j>=1

#include<iostream>
#include<vector>
using namespace std;

int numDistinct(string s, string t) {
    int len1 = s.size();
    int len2 = t.size();
    if(len1==0 || len2==0)
        return 0;
    vector<vector<int> > table(len1);
    for(int i=0;i<len1;i++){
        table[i].resize(len2);
    }
    table[0][0] = (s[0]==t[0]);
    for(int i=1;i<len2;i++){
        table[0][i] = 0;
    }
    for(int i=1;i<len1;i++){
        table[i][0] = (s[i]==t[0])+table[i-1][0];
    }
    for(int i=1;i<len1;i++){
        for(int j=1;j<len2;j++){
            if(s[i]==t[j])
                table[i][j] = table[i-1][j-1] + table[i-1][j];
            else
                table[i][j] = table[i-1][j];
        }
    }
    return table[len1-1][len2-1];
}

int main(){
    cout<<numDistinct("rabbbit", "rabbit")<<endl;
}


