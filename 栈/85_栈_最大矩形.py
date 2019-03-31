# 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

test = []
test = [['0','0','0'],['0','0','0'],['0','0','0'],['0','0','0']]
test = [['0','1'],['1','0']]

# 问题抽象：84中求了柱状图中的最大矩形，如果将84中的柱状图扩展到2维，并限制每个元素的高度非零即一，那么便可得到该题。由于每个元素非零即一，所以该
# 2维问题其实是个伪2维问题，它本质上是个一维的问题，完全可以复用84题中的代码。对每一行进行遍历，对行中的每个元素，如果为1，向上求其最大高度，零则
# 截止，这样得到的列表给84题中的代码，就可以得到截止到该行的最大矩形面积。最后再求最大值即可。
# 解决方式：如下：
def largestRectangleArea(heights):
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

def maximalRectangle(matrix):
    print(matrix)
    row_length = len(matrix)
    if row_length == 0:
        return 0
    col_length = len(matrix[0])
    heights = [[0 for i in range(col_length)] for q in range(row_length)]
    print(heights)
    # 对0行赋值要提前检查
    for i in range(col_length):
        heights[0][i] = int(matrix[0][i])
    #print(heights)
    #print(matrix)
    for i in range(1, row_length):
        for q in range(col_length):
            if matrix[i][q] == '1':
                heights[i][q] = heights[i-1][q] + 1
    #print(heights)
    my_max = 0
    for i in heights:
        my_max = max(my_max, largestRectangleArea(i))
    return my_max

print(maximalRectangle(test))

# 思：如何得到3维柱状图中最大立方体的体积？