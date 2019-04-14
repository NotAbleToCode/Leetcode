// 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。

// '?' 可以匹配任何单个字符。
// '*' 可以匹配任意字符串（包括空字符串）。
// 两个字符串完全匹配才算匹配成功。

// 说明:

// s 可能为空，且只包含从 a-z 的小写字母。
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
// 示例 1:

// 输入:
// s = "aa"
// p = "a"
// 输出: false
// 解释: "a" 无法匹配 "aa" 整个字符串。
// 示例 2:

// 输入:
// s = "aa"
// p = "*"
// 输出: true
// 解释: '*' 可以匹配任意字符串。
// 示例 3:

// 输入:
// s = "cb"
// p = "?a"
// 输出: false
// 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
// 示例 4:

// 输入:
// s = "adceb"
// p = "*a*b"
// 输出: true
// 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
// 示例 5:

// 输入:
// s = "acdcb"
// p = "a*c?b"
// 输出: false

// 问题分析
// 定义状态，f(i,j)为p[0:j]可以匹配s[0:i]
// 状态转移，对于f(i,j)：
// 若s[i]==p[j]（p[j]为字母），此时若匹配，则s[i]必和p[j]匹配，则f(i,j)=f(i-1,j-1)
// 若s[i]!=p[j]
//  若p[j]=='*'，则p[j]可以匹配任意字符串，故只需p[0:j-1]能匹配s[0:i]或s[0:i-1]或...s[0:0]即可，故f(i,j)=f(i,j-1)||f(i-1,j-1)||...||f(0,j-1)
//  若p[j]=='?'，则若匹配，必有s[i]==p[j]，故此时f(i,j)=f(i-1,j-1)
// 状态初始化，可以看到，初始化以及状态求取的步骤，可以如下：
// 初始化矩阵的第一行和第一列，然后从f(1,1)开始，每列遍历，最后输出f(s.size()-1,p.size()-1)即可
// 时间复杂度O(s.size()*p.size())

#include<iostream>
#include<vector>
using namespace std;

bool isMatch(string s, string p){
    int row = s.size();
    int col = p.size();
    vector<vector<bool> > table(row);
    vector<vector<bool> > all_or(row);
    for(int i=0;i<row;i++){
        table[i].resize(col);
        all_or[i].resize(col,false);
    }
    if(row==0 && col==0){
        return true;
    }
    else if(row==0 && col!=0){
        if(col==1 && p[0]=='*'){
            return true;
        }
        return false;
    }
    else if(row!=0 && col==0){
        return false;
    }
    table[0][0] = (s[0]==p[0] || p[0]=='*' || p[0]=='?');
    // 第一行是否只有*
    bool flag = (p[0]=='*');
    // 第一行初始化
    for(int j=1;j<col;j++){
        if(p[j]=='*'){
            if(flag){
                table[0][j] = true;
            }
            else{
                table[0][j] = table[0][j-1];
            }
        }
        else if(p[j]=='?'){
            if(flag){
                table[0][j] = true;
            }
            else{
                table[0][j] = false;
            }
        }
        else{
            if(p[j]==s[0]){
                table[0][j] = flag;
            }
            else{
                table[0][j] = false;
            }
        }
        flag = flag && (p[j]=='*');
    }
    // 第一列初始化
    for(int i=1;i<row;i++){
        if(p[0]=='*'){
            table[i][0] = true;
        }
        else{
            table[i][0] = false;
        }
    }
    for(int j=0;j<col;j++){
        all_or[0][j] = table[0][j];
    }
    // 第一列，或运算的累积初始化
    for(int i=1;i<row;i++){
        all_or[i][0] = table[i][0] || all_or[i-1][0];
    }   
    for(int j=1;j<col;j++){
        for(int i=1;i<row;i++){
            
            if(s[i]==p[j]){
                table[i][j] = table[i-1][j-1];
            }
            else{
                if(p[j]=='*'){
                    table[i][j] = all_or[i][j-1];
                }
                else if(p[j]=='?'){
                    table[i][j] = table[i-1][j-1];
                }
                else{
                    table[i][j] = false;
                }
            }
            all_or[i][j] = table[i][j] || all_or[i-1][j];
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            cout<<all_or[i][j]<<" ";
        cout<<endl;
    }
    return table[row-1][col-1];
}

int main(){
    // cout<<isMatch("aa","a")<<endl;
    // cout<<isMatch("aa","*")<<endl;
    // cout<<isMatch("cb","?a")<<endl;
    // cout<<isMatch("adceb","*a*b")<<endl;
    // cout<<isMatch("ac","a*c?b")<<endl;
    cout<<isMatch("ho","**ho")<<endl;
}