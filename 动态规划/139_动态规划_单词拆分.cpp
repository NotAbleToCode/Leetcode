// 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

// 说明：

// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。
// 示例 1：

// 输入: s = "leetcode", wordDict = ["leet", "code"]
// 输出: true
// 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 示例 2：

// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
// 输出: true
// 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//      注意你可以重复使用字典中的单词。
// 示例 3：

// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// 输出: false


// 状态f(i)，s[0:i]是否可以用字典中的单词拆分
// 状态转移f(i) = f(i-k) && (s[i-k:i] in wordDict)

#include<iostream>
#include<vector>
using namespace std;

bool my_find(string a, vector<string>& wordDict){
    for(int i=0;i<wordDict.size();i++){
        if(a==wordDict[i])
            return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    vector<bool> f(len, false);
    for(int i=0;i<len;i++){
        for(int j=0;j<wordDict.size();j++){
            int temp_len = wordDict[j].size();
            if(i+1>=temp_len && ((i-temp_len==-1||f[i-temp_len])) && my_find(s.substr(i-temp_len+1, temp_len), wordDict)){
                f[i] = true;
                break;
            }
        }
    }
    return f[len-1];
}

int main(){
    string s = "leetcode";
    vector<string> wordDict{"leet", "code"};
    cout<<wordBreak(s, wordDict)<<endl;
}