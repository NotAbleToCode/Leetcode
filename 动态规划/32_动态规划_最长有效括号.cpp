// 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

// 示例 1:
// 输入: "(()"
// 输出: 2
// 解释: 最长有效括号子串为 "()"
// 示例 2:

// 输入: ")()())"
// 输出: 4
// 解释: 最长有效括号子串为 "()()"

// 题目分析
// 该题可以从动态规划的角度来想，类比最长回文子串
// 定义状态：f(i,j)，从下标i开始到下标j结束的子串是否是有效括号
// 初始状态：初始化长度为1的和长度为2的子串，是否为有效括号
// 状态转移：f(i,j) = f(i+1,j-1) & f(i)=='(' & f(j)==')'
// 这样的动态规划时间空间复杂度都是O(n^2)，很容易超时

// 可以定义另一种状态
// 定义状态：f[i]，以i为结尾的最长有效括号的长
// 初始状态：f[0]=0
// 状态转移：if (s[i] == ')' & i-f[i-1]-1>=0 & s[i-f[i-1]-1]=='(') 则f[i]=f[i-1]+2 + f[i-f[i-1]-2](如果i-f[i-1]-2>=0)
//          else f(i) = 0
// 动态规划的状态，一般有bool型和数值型两类，对于状态f(n)，bool型一般表示n是或不是某种状态，数值型一般表示以n为界限的最优的值。
// 一般来说，数值型的动态规划更难设计，但也更有效，如本题
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// 可以用栈来写，时间复杂度O(n^2)
int longestValidParentheses(string s) {
    int length = s.size();
    vector<bool> flag(length,false);
    stack<int> my_stack;
    for(int i=0;i<length;i++){
        if(s[i]=='('){
            my_stack.push(i);
        }
        else{
            if(!my_stack.empty()){
                flag[my_stack.top()]=true;
                flag[i]=true;
                my_stack.pop();
            }
        }
    }
    int my_max = 0;
    int cur_max = 0;
    for(int i=0;i<length;i++){
        if(flag[i]==true){
            cur_max += 1;
        }
        else{
            my_max = max(my_max, cur_max);
            cur_max = 0;
        }
    }
    return max(my_max,cur_max);
}

int main(){
    cout<<longestValidParentheses("(()")<<endl;
}