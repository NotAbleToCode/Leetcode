// 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。

// 示例:

// 输入: 3
// 输出:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// 解释:
// 以上的输出对应以下 5 种不同结构的二叉搜索树：

//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


// 思路见96
// 动态规划的思想，用递归来实现

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> sub_generateTrees(int a, int b) {
    cout<<a<<" "<<b<<endl;
    if(a>b){
        vector<TreeNode*> root(1);
        root[0] = NULL;
        return root;
    }
    TreeNode* temp_node = NULL;
    vector<TreeNode*> roots;
    vector<TreeNode*> left;
    vector<TreeNode*> right;
    for(int i=a;i<=b;i++){
        left = sub_generateTrees(a,i-1);
        right = sub_generateTrees(i+1,b);
        for(int a=0;a<left.size();a++){
            for(int b=0;b<right.size();b++){
                temp_node = new TreeNode(i+1);
                temp_node->left = left[a];
                temp_node->right = right[b];
                roots.push_back(temp_node);
            }
        }
    }
    return roots;
}

vector<TreeNode*> generateTrees(int n) {
    vector<TreeNode* > roots;
    TreeNode* temp_node = NULL;
    vector<TreeNode*> left;
    vector<TreeNode*> right;
    for(int i=0;i<n;i++){
        // 一共0到n-1个数，每个数依次做根结点
        left = sub_generateTrees(0,i-1);
        right = sub_generateTrees(i+1,n-1);
        // 根结点
        for(int a=0;a<left.size();a++){
            for(int b=0;b<right.size();b++){
                temp_node = new TreeNode(i+1);
                temp_node->left = left[a];
                temp_node->right = right[b];
                roots.push_back(temp_node);
            }
        }
    }
    return roots;
}

int main(){
    generateTrees(5);
}