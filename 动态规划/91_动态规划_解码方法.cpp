// 一条包含字母 A-Z 的消息通过以下方式进行了编码：

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// 给定一个只包含数字的非空字符串，请计算解码方法的总数。

// 示例 1:

// 输入: "12"
// 输出: 2
// 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
// 示例 2:

// 输入: "226"
// 输出: 3
// 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。

// 状态f(i)，以下标i为结束的子串的所有解码方法
// 状态转移
//  i等于0，且i和前一个数字组成10或20，此时f(i)=f(i-1)，否则f(i)=0
//  i不等于0，若i被当做单独数字解码，则方法数g=f(i-1)，
//  若i不被当做单独数字解码，i-1等于0，则f(i)=f(i-1)，i-1不等于0，则若i和前面的数字组成的数在1到26之间，f(i)=f(i-1)+f(i-2)，否则f(i)=f(i-1)
// 状态初始化
//  要初始化f(0)和f(1)，规则和上述类似

#include<iostream>
#include<vector>
using namespace std;

int numDecodings(string s) {
    int len = s.size();
    if(len==0){
        return 0;
    }
    vector<int> table(len);
    if(s[0]=='0')
        table[0] = 0;
    else
        table[0] = 1;
    if(len==1)
        return table[0];
    if(s[1]=='0'){
        if(s[0]=='0')
            table[1] = 0;
        else{
            if(stoi(s.substr(0,2))<=26 && stoi(s.substr(0,2))>=1){
                table[1] = 1;
            }
            else
                table[1] = 0;
        }
    }
    else{
        if(s[0]=='0')
            table[1]=0;
        else{
            if(stoi(s.substr(0,2))<=26 && stoi(s.substr(0,2))>=1){
                table[1] = table[0]+1;
            }
            else
                table[1] = table[0];
        }
    }
    for(int i=2;i<len;i++){
        if(s[i]=='0'){
            if(s[i-1]=='0')
                table[i] = 0;
            else{
                if(stoi(s.substr(i-1,2))<=26 && stoi(s.substr(i-1,2))>=1){
                    table[i] = table[i-2];
                }
                else{
                    table[i] = 0;
                }
            }
        } 
        else{
            if(s[i-1]=='0')
                table[i] = table[i-1];
            else{
                if(stoi(s.substr(i-1,2))<=26 && stoi(s.substr(i-1,2))>=1){
                    table[i] = table[i-1]+table[i-2];
                }
                else
                    table[i] = table[i-1];
            }
        }

    }
    for(int i=0;i<len;i++)
        cout<<table[i]<<" ";
    cout<<endl;
    return table[len-1];
}


int main(){
    cout<<numDecodings("227")<<endl;
}