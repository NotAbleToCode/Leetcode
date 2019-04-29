// 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

// 返回符合要求的最少分割次数。

// 示例:

// 输入: "aab"
// 输出: 1
// 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

// 先用O(n^2)算法得到对任意的下标i，j，s[i:j]是否为回文串，可参考5_动态规划_最长回文子串.cpp
// 然后，定义f(i)为以下标i为结尾的可以划分为最短回文串的个数，f(i)一开始初始化为i+1，则f(i) = min(f(i), f(i-k)+1)，其中s[i-k:i]为回文串

// 这道题用了两次动态规划，解题时不要局限于一次动态规划

#include<iostream>
#include<vector>
using namespace std;

int minCut(string s) {
    int len = s.size();
    if(len==0){
        return 0;
    }
    // 用于确定s[i:j]是否为回文串
    vector<vector<bool> > f1(len, vector<bool>(len, true));
    for(int i=0;i<len-1;i++){
        f1[i][i+1] = s[i]==s[i+1];
    }
    for(int i=2;i<len;i++){
        for(int j=0;j<len-i;j++){
            f1[j][j+i] = f1[j+1][j+i-1] && (s[j]==s[j+i]);
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++)
            cout<<f1[i][j]<<" ";
        cout<<endl;
    }
    // 用于确定最小分割数
    // 对于以第i个字符为结尾的最小分割方案，第i个字符肯定是某个回文串中的一部分（包括自己组成的回文串），遍历取最小，然后加一即可。
    vector<int> f2(len+1, 0);
    for(int i=0;i<len+1;i++){
        f2[i] = i-1;
    }
    for(int i=2;i<len+1;i++)
    {

        for(int j=1;j<=i;j++){
            if(f1[j-1][i-1]){
                f2[i] = min(f2[i], f2[j-1]+1);
            }
        }
    }
    for(int i=0;i<len+1;i++)
        cout<<f2[i]<<" ";
    cout<<endl;
    return f2[len];
}

int main(){
    cout<<minCut("aab")<<endl;
}