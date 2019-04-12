// 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符

// 动态规划
// 对于很多动态规划，首先不要转化问题，先尝试在小问题上研究问题，再定义状态转移
// 转化问题往往可能会使问题麻烦
// 譬如该题，一开始设想，找出word1中（在word1内可以间断，保证顺序即可）含word2最长连续子串的长度即可。
// 但不如直接对问题进行小问题变化
// 该题的小问题就是，以i下标结尾的word1子串，变为以j下标结尾的word2子串的所使用的最少操作数
// 当i=len(word1),j=len(word2)时，就是原问题
// 状态f(i,j)，定义如上
// 初始状态，f(0,0) = 1 if word1[0]==word2[0] else 0
// 状态转移
// 考虑f(i+1,j+1)
// 若word1[i+1]==word2[j+1]，那么自然f(i+1,j+1)=f(i,j)
// 若二者不等，则讨论如下：
// 对于word1[i+1]，在用最少操作数变为word2时，其要么被删除，要么被替换，要么被保留。
// 计算每种操作下的最优操作数，然后取最小值，就是实际的最优操作数了
// 如果是被删除，那么删除后，最优步骤数就是word1[0:i]转化为word2的最优步骤数，因此g(i+1,j+1)=f(i,j+1)+1，1为删除操作
// 如果是被替换，那么word1[i+1]肯定被替换为word2[j+1]，要不然最后一个字母不相等。
// 那么替换后，最优操作数便是word1[0:i]转化为word2[0:j]，故g(i+1,j+1)=f(i,j)+1
// 如果是保留，那么最优操作数就是word1转化为word2[0:j]，然后加一个插入操作，插入word2[j+1]，故g(i+1,j)=f(i,j+1)+1
// 因此状态转移f(i+1,j+1) = min(f(i,j+1),f(i,j),f(i,j+1))+1
// 可以看到，状态转移是根据矩阵中左边，左上，上边的三个值来得到当前状态值，因此初始化还要考虑矩阵最左侧一列，最上面一行，然后就可以求解了
// 初始化步骤，以f(i,0)为例，若word1[i]==word2[0]，i之前全部删除，共i个删除操作。
// 若不等，i元素必删除，最优操作数为f(i-1,0)+1（删除操作）。
// 时间复杂度O(n^2)

#include<iostream>
#include<vector>
using namespace std;

int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    if(len1==0){
        return len2;
    }
    if(len2==0){
        return len1;
    }
    vector<vector<int> > table(len1);
    for(int i=0;i<len1;i++){
        table[i].resize(len2);
    }
    table[0][0] = (word1[0]==word2[0])?0:1;
    for(int i=1;i<len1;i++){
        if(word1[i]==word2[0])
            table[i][0] = i;
        else
            table[i][0] = table[i-1][0]+1;
    }
    for(int i=1;i<len2;i++){
        if(word1[0]==word2[i])
            table[0][i] = i;
        else
            table[0][i] = table[0][i-1]+1;
    }
    for(int i=1;i<len1;i++){
        for(int j=1;j<len2;j++){
            if(word1[i]==word2[j]){
                table[i][j] = table[i-1][j-1];
            }
            else{
                table[i][j] = min(min(table[i-1][j],table[i-1][j-1]),table[i][j-1])+1;
            }
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    return table[len1-1][len2-1];
}

int main(){
    cout<<minDistance("intention", "execution")<<endl;
}
