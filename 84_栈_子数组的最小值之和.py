# 给定一个整数数组 A，找到 min(B) 的总和，其中 B 的范围为 A 的每个（连续）子数组。

# 由于答案可能很大，因此返回答案模 10^9 + 7。

# 示例：
# 输入：[3,1,2,4]
# 输出：17
# 解释：
# 子数组为 [3]，[1]，[2]，[4]，[3,1]，[1,2]，[2,4]，[3,1,2]，[1,2,4]，[3,1,2,4]。 
# 最小值为 3，1，2，4，1，1，2，1，1，1，和为 17。

# 问题分析：假设数组有n个值，考查第i个元素在计算总和的过程中被加了几次：
# 首先，包含第i个元素的连续数组一共有n个：第i个元素，第i个元素和前一个元素，第i个元素和前两个元素......
# 第i个元素和后一个元素，第i个元素和后两个元素......
# 一共有n个连续数组
# 而第i个元素，作为最小值在这些连续数组中出现的次数，就是该元素应该被加的次数。
# 那么第i个元素作为最小值出现了几次呢？
# 第i个元素向前的最近的比它小的元素下标记为a，向后的最近的比它小的元素下标记为b
# 那么作为最小值出现了b-a+1次

# 问题简化：
# 找出每个元素，两侧的第一个比它小的值。
# 该问题，和求柱状图中最大矩形的面积，其实是一个问题
# 用单调栈来求解：思路见84柱状图中最大矩形。
# 时间复杂度，运算主要是比较运算，从比较结果来对比较运算进行分类，比较结果为大于等于的运算，会导致一个元素入栈，由于一共有n个元素，那么
# 该类运算最多有n次，比较结果为小于的运算，会导致栈内元素出栈，而最多有n次出栈，故该运算最多有n次，因此时间复杂度为O(n)

class Solution:
    def sumSubarrayMins(A):
        my_stack

# typedef long long ll;
# class Solution {
#     const int P=1000000007;
# public:
#     int sumSubarrayMins(vector<int>& a) {
#         int n=a.size();
#         vector<int> l(n,-1),r(n,n),st;
#         for(int i=0;i<n;i++){
#             while(!st.empty()&&a[st.back()]>a[i])
#                 st.pop_back();
#             if(!st.empty())
#                 l[i]=st.back();
#             st.push_back(i);
#         }
#         st.clear();
#         for(int i=n-1;i>=0;i--){
#             while(!st.empty()&&a[st.back()]>=a[i])st.pop_back();
#             if(!st.empty())r[i]=st.back();
#             st.push_back(i);
#         }
#         int ans=0;
#         for(int i=0;i<n;i++){
#             int d=r[i]-l[i]-1;
#             ans=(ll(ans)+ll(i-l[i])*ll(r[i]-i)*ll(a[i]))%P;
#         }
#         return ans;
#     }
# };
