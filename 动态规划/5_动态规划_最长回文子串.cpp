// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。
// 示例 2：
// 输入: "cbbd"
// 输出: "bb"

// 动态规划
// 动态规划的基本定义及解释：
// 动态规划的基本形式是，求出n状态的值f(n)，f(n)和问题的目标直接挂钩
// 而为求出f(n)，只需要知道几个更小的f(c)。我们将求解f(c)称作求解f(n)的“子问题”。
// 我们将求解f(c)称作求解f(n)的“子问题”。
// 这就是DP（动态规划，dynamic programming）.
// 将一个问题拆成几个子问题，分别求解这些子问题，即可推断出大问题的解。
// 有关动态规划的问题，常常需要求出所有的状态f(i)，若单独对每个f(i)做分析，往往会超时
// 而动态规划揭露了状态和状态之间的联系，一个状态和之前的某些状态有关，且可以利用之前的某些状态快速得出当前的状态

// 设计一个动态规划的基本步骤：
// 我是谁？ ——设计状态，表示局面，一般情况下，状态就是题目中要求我们求的状态
// 我从哪里来？ ——初始化初始状态
// 我要到哪里去？ ——设计转移

// 根据如上思想，对问题分析如下：
// 设计状态p(i,j)，取值true或者false，代表从第i个字符开始，到第j个字符结束的子串是否为回文串。
// 可以知道，共n*n个状态，如果知道所有状态的值，那么取值为true的i和j差值最大的对应的子串即为所求。
// 所以，该问题本质上是一个有关动态规划问题：如何有效求出所有p(n1,n2)
// 初始状态，所有i=j和|i-j|=1的字符串，可以在O(n)时间内初始化完成
// 状态转移：p(i,j)=p(i+1,j-1)(s[i+1:j-1]为回文) & s[i]==s[j]
// 这样对每个状态，常数时间即可求出状态值。O(n^2)复杂度。
// 事实上，有O(n)的算法，Manacher算法，较复杂

// 编程时要注意求状态值的顺序，从小问题开始求

#include<iostream>
#include<vector>
using namespace std;
 
string longestPalindrome(string s) {
    int length = s.size();
    vector<vector<int> > table(length);
	for(int i = 0; i<length; i++){
		table[i].resize(length,true);
	} 
	for(int i=0;i<length-1;i++){
		table[i][i+1] = (s[i]==s[i+1]);
	}
	for(int i=2;i<length;i++){ 
		for(int q=i;q<length;q++){
			table[q-i][q] = table[q-i+1][q-1] & (s[q-i]==s[q]);
		}
	}
//	for(int i=0;i<length;i++){
//		for(int q=0;q<length;q++){
//			cout<<table[i][q];
//		}
//		cout<<endl; 
//	}
	int count = length-1;
	while(count>=0){
		for(int i=count;i<length;i++){
			//cout<<i-count<<i<<endl;
			if(table[i-count][i]==true){
				return s.substr(i-count,count+1);
			}
		}
		count-=1;
	}
	return s;
}

int main(){
	string s = longestPalindrome("babad");
	cout<<s<<endl;
}

