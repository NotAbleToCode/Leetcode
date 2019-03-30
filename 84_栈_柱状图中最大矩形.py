# 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
# 求在该柱状图中，能够勾勒出来的矩形的最大面积。


# 问题抽象：一个数组，求每一个元素的左（右）侧第一个比它小的元素的下标，
# 解决方式1：暴力求解，O(n^2)，容易超时
test = [2,1,5,6,2,3]
def largestRectangleArea_1(heights):
    left = [i for i in range(len(heights))]
    right = left[:]
    for i in range(len(heights)):
        for q in range(i+1,len(heights)):
            if heights[q] < heights[i]:
                right[i] = q
                break
        else:
            right[i] = len(heights)
    for i in reversed(range(len(heights))):
        for q in reversed(range(i)):
            if heights[q] < heights[i]:
                left[i] = q
                break
        else:
            left[i] = -1
    my_max = 0
    for i,q,height in zip(left, right, heights):
        my_max = max((q-i-1)*height, my_max)
    return my_max
    
# 解决方式2
# 暴力解法的缺点在于，没有很好地利用已经得到的信息。

# 问题分析：
# 最终得到的矩形，肯定是以某个柱子为上确界的。假如不是，那么这个矩形包括的所有柱子都比矩形高，那么矩形完全可以再上移，从而面积增大，矛盾。
# 因此，我们只需要得到，对任意一个柱子，以该柱子为上确界的最大矩形面积。然后比较所有矩形面积即可。
# 以某一柱子为上确界的最大矩形面积如何求呢？让该柱子向左右两边扩展，直到扩展不了（遇到比该柱子高度小的柱子）位置，此时面积为最大面积。
# 即，求左右两边第一个小于该柱子高度的柱子的下标即可。
# 如何求呢？考虑构造一个单调栈（栈内元素保证是单调递增/递减的栈）
# 首先求每个元素左边最近的比它小的元素下标
# 从左到右遍历元素，对每一个元素，若栈顶元素大于该元素，出栈，直到栈顶元素小于该元素，或者栈为空为止，此时栈顶元素的下标就是
# 该元素左边最近的比它小的元素，然后该元素入栈，继续进行
# 右边，反向遍历即可

def largestRectangleArea_2(heights):
    left = [i-1 for i in range(len(heights))]
    right = [i+1 for i in range(len(heights))]
    my_stack = []
    for i in range(len(heights)):
        while len(my_stack) != 0 and heights[my_stack[-1]] >= heights[i]:
            my_stack.pop()
        if len(my_stack) != 0:
            left[i] = my_stack[-1]
        else:
            left[i] = -1
        my_stack.append(i)
    my_stack = []
    for i in reversed(range(len(heights))):
        while len(my_stack) != 0 and heights[my_stack[-1]] >= heights[i]:
            my_stack.pop()
        if len(my_stack) != 0:
            right[i] = my_stack[-1]
        else:
            right[i] = len(heights)
        my_stack.append(i)
    my_max = 0
    for i in range(len(heights)):
        my_max = max(my_max, (right[i]-left[i]-1)*heights[i])
    return my_max

print(largestRectangleArea_2(test))

