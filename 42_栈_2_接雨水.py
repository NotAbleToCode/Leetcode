# 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

# 问题抽象：找出每一个凹坑，然后求存储的水量，如果小凹坑被大凹坑包含，那么以大凹坑为准
# 解决方式：
# 首先选取第一个不为零的板counter，然后向后遍历
# 遇到和它相等或比它高的板，可以直接结算存储的雨水量，然后更新counter，接着向后遍历
# 遇到比它低的板，继续遍历，直到遍历结束
# 如果此时counter不是最后一个板，说明counter后没有比counter高的板，那么从最后一个板到counter按上述规则反向遍历即可
# 如果counter是最后一个板，那么直接返回存储的雨水量即可
test = [4,2,3]
def trap_1(test):
    print(test)
    my_sum = 0
    if len(test) == 0 or sum(test) == 0:
        return 0
    counter = 0
    while test[counter] == 0:
        counter += 1
    current = counter+1
    while current < len(test):
        while test[current] < test[counter]:
            current += 1
            if current >= len(test):
                break
        if current >= len(test):
            if current == counter+1:
                return my_sum
            else:
                # print(list(reversed(test[counter:])))
                return my_sum + trap_1(list(reversed(test[counter:])))
        else:
            my_sum += test[counter]*(current-counter-1) - sum(test[counter+1:current])
            counter = current
            current = counter + 1
    return my_sum

# 问题抽象：找到每一个元素左（右）侧的最大值，就可以计算该位置的水量
# 解决方式：
# 创建两个数组left和right
# 然后进行计算，分别令两个数组的第i个位置记录第i个板左侧最大值和右侧最大值
# 那么第i个板如果比两侧最大值的最小值高，那么不能存水，反之可以存差值量的水
def trap_2(height):
    water = 0
    left = [0]*len(height)
    right = [0]*len(height)
    length = len(height)
    for i in range(1,length):
        left[i] = max(left[i-1], height[i-1])
    for i in reversed(range(0,length-1)):
        right[i] = max(right[i+1], height[i+1])
    for i in range(1, length-1):
        water += max(0, min(left[i], right[i])-height[i])
    return water
    
print(trap_2(test))    

# 思考
# 问题抽象很重要，好的抽象可以将问题转化为更易理解和解决的数学问题。

