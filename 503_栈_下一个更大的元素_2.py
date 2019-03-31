# 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。
# 数字 x 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。
# 如果不存在，则输出 -1。

# 对于列表中的所有元素
# 确定该元素左边最后一个比该元素大的
# 确定该元素右边第一个比该元素大的

# 左边最后一个比该元素大的，其实就是循环向右遍历，右边第一个比该元素大的
# 令nums=nums+nums，那么得到的结果，就是右边第一个比该元素大的

def nextGreaterElements(nums):
    right = [-1]*2*len(nums)
    nums_double = nums + nums
    my_stack = []
    for i in reversed(range(len(nums_double))):
        while len(my_stack) != 0 and my_stack[-1] <= nums_double[i]:
            my_stack.pop()
        if len(my_stack) != 0:
            right[i] = my_stack[-1]
        my_stack.append(nums_double[i])
    ans = right[0:len(nums)]
    return ans

print(nextGreaterElements([1,2,1]))

