// 给定一个未排序的整数数组，找出最长连续序列的长度。

// 要求算法的时间复杂度为 O(n)。

// 示例:

// 输入: [100, 4, 200, 1, 3, 2]
// 输出: 4
// 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

// 并查集的问题一般形式如下：
// 1.给出若干个元素
// 2.给出若干个元素对，每个元素对代表了两个元素之间存在联系
// 3.这样的联系是有传递性的
// 4.求解的问题一般为：
//   任意给两个元素，判断两个元素之间是否有联系
//   有联系的元素放入同一集合中，计算所有集合的个数（连通分量的个数），计算元素最多的集合的元素个数

// 问题分析
// 一个用并查集求最大连通分量的问题
// 定义元素：序列中出现的整数
// 定义关系：序列中的两个数a和b(a<b)，若a+1,a+2...b-1也在序列中，则a和b具有关系
// 关系的传递性证明：易知a和b有关系，b和c有关系，那么a和c肯定有关系
// 关系的获得：该题不是显式给出关系的，但有O(n)的方法将关系得到：
//  首先初始化nums.max-nums.min+1长度的int数组f，初始值为-1，然后遍历nums，将出现的f[nums[i]-nums.min]变为i。
//  然后遍历nums，对于f[nums[i]-nums.min]，若f[nums[i]-nums.min-1]不为-1，那么说明其前面有值，即数组中出现了nums[i]和nums[i]-1两个数，这两个数是具有关系的。
//  只需考虑前面的即可，后面的不用考虑。因为是要遍历完一遍的，考虑前面的又考虑后面的会引起重复。
//  从而，2n次遍历就获得了所有关系。
//  不过，实际测试，内存会爆，推荐用map
// 根据关系构造并查集，并查集中最大的连通分量即为最长连续序列的长度。
// 注意设定一个辅助数组nodenum[]。其中nodenum[i] = x表示i所在集合的节点数目为x。这样在Union()操作时，改变根节点的同时更新nodenum的数值。
// 并查集森林构建完毕后，对parent[]数组遍历，如果存在parent[i] = i的情况，说明i是一个树根。然后求得nodenum[i]的最大值即可。
// 可能会有重复值的情况，并不影响算法正确性

#include<iostream>
#include<vector>
#include<map>
using namespace std;

// 包含路径压缩算法的搜索
int find_root(vector<int>& union_check_set, int index){
    // cout<<index<<endl;
    // cout<<"hehe"<<endl;
    if(union_check_set[index]!=index){
        union_check_set[index] = find_root(union_check_set, union_check_set[index]);
        return union_check_set[index];
    }
    else{
        return index;
    }
}
// 将index_1和index_2合并
void unite(vector<int>& union_check_set, vector<int>& node_num, vector<int>& height, int index_1, int index_2){
    int root_1 = find_root(union_check_set, index_1);
    int root_2 = find_root(union_check_set, index_2);
    if(root_1!=root_2){
        if(height[root_1]>height[root_2]){
            union_check_set[root_2] = root_1;
            node_num[root_1] += node_num[root_2];
        }
        else if(height[root_1]==height[root_2]){
            union_check_set[root_2] = root_1;
            height[root_1] += 1;
            node_num[root_1] += node_num[root_2];
        }
        else{
            union_check_set[root_1] = root_2;
            node_num[root_2] += node_num[root_1];
        }
    }
}

int longestConsecutive(vector<int>& nums) {
    int len = nums.size();
    if(len==0)
        return 0;
    map<int,int>table;
    // 初始化表
    for(int i=0;i<len;i++){
        table[nums[i]] = i;
    }
    vector<int> union_check_set(len,0);
    vector<int> node_num(len,1);
    // 子树的高度
    vector<int> height(len,1);
    // 每一个先和自己相连通
    for(int i=0;i<len;i++){
        union_check_set[i] = i;
    }
    // 根据表得连通关系
    // for(int i=0;i<my_max-my_min+1;i++)
    //     cout<<table[i]<<" ";
    // cout<<endl;
    for(int i=0;i<len;i++){
        if(table.find(nums[i]) != table.end()&&table.find(nums[i]-1) != table.end()){
            unite(union_check_set, node_num, height, table[nums[i]], table[nums[i]-1]);
            // for(int i=0;i<len;i++)
            //     cout<<union_check_set[i]<<" ";
            // cout<<endl;
            // for(int i=0;i<len;i++)
            //     cout<<node_num[i]<<" ";
            // cout<<endl<<endl;
        }
    }
    // 求最大的连通分量
    int longest = 0;
    for(int i=0;i<len;i++)
        longest = max(longest, node_num[i]);
    return longest;
}
int main(){
    vector<int> test{100, 4, 200, 1, 3, 2};
    //vector<int> test{9,1,-3,2,4,8,3,-1,6,-2,-4,7};
    cout<<longestConsecutive(test)<<endl;
}