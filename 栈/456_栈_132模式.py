# 给定一个整数序列：a1, a2, ..., an，一个132模式的子序列 ai, aj, ak 被定义为：当 i < j < k 时，ai < ak < aj。
# 设计一个算法，当给定有 n 个数字的序列时，验证这个序列中是否含有132模式的子序列。

# 注意：n 的值小于15000。

# 问题分析：
# 首先，若一个元素是132模式中的3，那么其左侧是否存在1，肯定能由左侧最小值来确定。
#   若左侧的最小值都比右侧的2大，那么便不会存在该元素是3的132模式。
#   因此，对每一32组合，只需要考查3左侧最小值，看是否小于2即可
#   因此，我们可以先用O(n)的方法得到每一个元素左侧最小值，然后对每一个元素，遍历其后面的所有元素，看是否有在该元素值和该元素左侧最小值之间的元素。
#   如果有，返回True，没有，返回False。
#   时间复杂度O(n^2)，超时
test = [1, 2, 3, 4]
def find132pattern_1(nums):
    if len(nums) == 0:
        return False
    left = [-1]*len(nums)
    curr_min = nums[0]
    # 求左侧最小值
    for i in range(1, len(nums)):
        left[i] = curr_min
        curr_min = min(curr_min, nums[i])
    # 根据当前元素和当前元素左侧最小元素来判断当前元素右侧元素是否有2
    for i in range(1,len(nums)):
        for q in range(i+1,len(nums)):
            if nums[q]>left[i] and nums[q]<nums[i]:
                return True
    return False

# 上述解法超时
# 我们可以从32的确定上来优化
# 上个解法，是暴力搜索所有的32组合的
# 但其实，对于2，2所有左侧比其大的数都可以作为3，但其实只需要考查其左侧第一个比它大的值作为3，这样一个32组合即可
# 首先，如果这样的32组合，3左侧的最小值小于2，那么返回true
# 其次，如果这样的32组合，3左侧的最小值大于等于2，即不存在，那么左侧第k（k>=2）个比它大的值的左侧的最小值，势必也大于等于2，也肯定不存在。
# 因此，若一个元素作为2，只需考查左侧第一个大于它的元素作为3，即可。
# 因此，首先O(n)得到每个元素左侧最小值，再O(n)得到每个元素左侧第一个比其大的值，然后O(n)遍历每一个元素，看一看该元素，该元素左侧第一个比其大的元素，
# 该元素左侧第一个比其大的元素的左侧最小元素，是否可以对应2,3,1，可以即返回True。
# 时间复杂度O(n)
test = [1, 2, 3, 4]
def find132pattern_2(nums):
    if len(nums) <= 2:
        return False
    curr_min = nums[0]
    # 左侧的最小值
    left_min = [-1]*len(nums)
    # 左侧第一个比其大的值的下标
    left_first_larger_index = [-1]*len(nums)
    curr_min = nums[0]
    my_stack = []
    for i in range(1, len(nums)):
        # 左侧最小值
        left_min[i] = curr_min
        curr_min = min(curr_min, nums[i])
        # 左侧第一个大的值的下标
        while len(my_stack) != 0 and nums[i] >= nums[my_stack[-1]]:
            my_stack.pop()
        if len(my_stack) != 0:
            left_first_larger_index[i] = my_stack[-1]
        my_stack.append(i)
    # 是否对应132
    for i in range(2, len(nums)):
        if left_first_larger_index[i] != -1:
            if left_min[left_first_larger_index[i]] < nums[i]:
                return True
    return False

print(find132pattern_2(test))