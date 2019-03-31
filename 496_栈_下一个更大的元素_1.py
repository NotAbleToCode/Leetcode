# 给定两个没有重复元素的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。找到 nums1 中每个元素在 nums2 中的下一个比其大的值。

# nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出-1。

def nextGreaterElement(nums1, nums2):
    # 单调栈求得nums2中每个元素右侧第一个比其大的元素
    # 时间复杂度O(n)
    my_stack = []
    right = [-1]*len(nums2)
    for i in reversed(range(len(nums2))):
        while len(my_stack) != 0 and my_stack[-1] <= nums2[i]:
            my_stack.pop()
        if len(my_stack) != 0:
            right[i] = my_stack[-1]
        my_stack.append(nums2[i])
    ans = [None]*len(nums1)
    for i in range(len(nums1)):
        ans[i] = right[nums2.index(nums1[i])]
    return ans

nums1 = [2,4]
nums2 = [1,2,3,4]
print(nextGreaterElement(nums1, nums2))



