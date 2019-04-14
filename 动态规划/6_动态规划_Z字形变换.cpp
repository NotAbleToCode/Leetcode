// 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。
// 比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：
// L   C   I   R
// E T O E S I I G
// E   D   H   N
// 之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。
// 请你实现这个将字符串进行指定行数变换的函数：
// string convert(string s, int numRows);

// 考虑Z字形排列的第k行
// 第k行的第一个字母是原字符串的下标为k-1的字母，它到下两个字母的下标增加量分别为
// (n-(k+2))*2+2和2*(k-2)+2
// 增加后，加入结果，一直到越界为止
// 注意第一行和最后一行会有增量为0的情况
// 注意n=1的时候直接输出原输入即可

#include<iostream>
#include<string>
using namespace std;

string convert(string s, int numRows) {
    int len = s.size();
    if(len==1)
        return s;
    string ans(len,' ');
    int count = 0;
    int temp = 0;
    int next;
    for(int i=0;i<numRows;i++){
        count = i;
        ans[temp++] = s[count];
        // 每一次，得到两个字母
        while(1){
            next = (numRows-(i+2))*2+2;
            if(next!=0){
                count+=next;
                if(count >= len)
                    break;
                ans[temp++] = s[count];
            } 
            next = 2*(i-1)+2;
            if(next!=0){
                count+=next;
                if(count >= len)
                    break;
                ans[temp++] = s[count];
            }       
        }
    }
    return ans;
}
int main(){
    cout<<convert("L", 1)<<endl;
}