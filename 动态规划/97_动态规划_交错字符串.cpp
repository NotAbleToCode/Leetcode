// 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。

// 示例 1:

// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// 输出: true
// 示例 2:

// 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// 输出: false

// 定义状态：f(i,j)，由s1[0:i]和s2[0:j]是否可以交错组成s3[0:i+j]
// 状态转移：交错字符串最后一个字母，要么来自于s1，要么来自于s2，若来自于s1，那么f(i,j)=f(i-1,j)，若来自于s2，那么f(i,j)=f(i,j-1)
//  因此f(i,j) = (f(i-1,j) && s1[i]==s3[i+j]) || (f(i,j-1) && s2[j]==s3[i+j])
// 状态初始化：初始化矩阵第一行和第一列即可
//  f(0,0) = (s3[0:1] == s1[0]|s2[0] || s3[0:1] == s2[0]|s1[0])
//  第一行：f(0,j)，如果s3最后一个字母来自s1[0]，则应s2[0:j]=s3[0:j-1]，如果来自s2[j]，则f(0,j)=f(0,j-1)
//  第一列：f(i,0)，如果s3最后一个字母来自s2[0]，则应s1[0:i]=s3[0:i-1]，如果来自s1[i]，则f(i,0)=f(i-1,0)

#include<iostream>
#include<vector>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.size();
    int len2 = s2.size();
    int len3 = s3.size();
    if(len3 != (len1+len2))
        return false;
    if(len1 == 0)
        return (s2==s3);
    if(len2 == 0)
        return (s1==s3);
    vector<vector<bool> > table(len1);
    for(int i=0;i<len1;i++)
        table[i].resize(len2);
    table[0][0] = (s1.substr(0,1)+s2.substr(0,1)==s3.substr(0,2)) || (s2.substr(0,1)+s1.substr(0,1)==s3.substr(0,2));
    for(int j=1;j<len2;j++)
        table[0][j] = (s1.substr(0,1)==s3.substr(j+1,1) && s2.substr(0,j+1)==s3.substr(0,j+1)) || (s2.substr(j,1)==s3.substr(j+1,1) && table[0][j-1]);
    for(int i=1;i<len1;i++)
        table[i][0] = (s2.substr(0,1)==s3.substr(i+1,1) && s1.substr(0,i+1)==s3.substr(0,i+1)) || (s1.substr(i,1)==s3.substr(i+1,1) && table[i-1][0]);
    for(int i=1;i<len1;i++)
        for(int j=1;j<len2;j++)
            table[i][j] = (s1.substr(i,1)==s3.substr(i+j+1,1) && table[i-1][j]) || (s2.substr(j,1)==s3.substr(i+j+1,1) && table[i][j-1]);
    // for(int i=0;i<len1;i++){
    //     for(int j=0;j<len2;j++)
    //         cout<<table[i][j]<<" ";
    //     cout<<endl;
    // }
    return table[len1-1][len2-1];
}
int main(){
    cout<<isInterleave( "ab", "bc", "babc")<<endl;
    //cout<<isInterleave("aabcc", "dbbca", "aadbbbaccc")<<endl;
}
